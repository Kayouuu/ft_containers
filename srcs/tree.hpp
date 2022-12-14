/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:19:50 by psaulnie          #+#    #+#             */
/*   Updated: 2022/12/19 15:00:32 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_HPP
# define TREE_HPP

// #include "ft_containers.hpp"
#include "map.hpp"
#include "pair.hpp"
#include <memory>
#include <iostream>
#include <map>
#include <functional>

template <typename Key, typename T>
struct	s_tree
{
	ft::pair<const Key, T>	data;
	s_tree<Key, T>			*parent;
	s_tree<Key, T>			*left;
	s_tree<Key, T>			*right;
	int						color; // either 0 => black or 1 => red
};

namespace ft
{
	template <
		class Key,
		class T,
		class Compare,
		class Allocator >
	class map;
}

/* *********************************Red-Black Tree Properties********************************* */
/*																							   */
/*	1-Every node in T is either red or black.												   */
/*	2-The root node of T is black.															   */
/*	3-Every NULL node is black. (NULL nodes are the leaf nodes. 							   */
/*	They do not contain any keys. When we search for a key that is not present in the tree,	   */
/*	we reach the NULL node.)																   */
/*	4-If a node is red, both of its children are black.										   */
/*	This means no two nodes on a path can be red nodes.										   */
/*	5-Every path from a root node to a NULL node has the same number of black nodes.		   */
/*																							   */
/*	*T represent our Red-Black Tree															   */
/* ******************************************************************************************* */

template <typename Key, typename T, typename Alloc, typename Comp>
class RedBlackTree
{
	public:
		typedef s_tree<Key, T>												*Node;
		typedef	ft::pair<const Key, T>										pair_type;
		typedef	typename Alloc::template rebind< s_tree<Key, T> >::other	alloc_type;
		typedef typename ft::map<Key, T, Comp, Alloc>::value_compare		compare;
		typedef ft::pair<const Key, T>										*pointer;
		typedef const ft::pair<const Key, T>								*const_pointer;

		Node						root;
		Node						TNULL;
		compare						comp;
		alloc_type					alloc;
		std::allocator<pair_type>	alloc_pair;
	private:
		void	left_rotate(Node x)
		{
			Node	y;
			y = x->right;
			x->right = y->left; // exchanging sub-trees
			if (y && y->left && y->left != TNULL) // if y is the root
				y->left->parent = x;
			y->parent = x->parent; // y new parent become x parent
			if (x->parent == NULL) // if x is the root, then y become the new root
				this->root = y;
			else if (x == x->parent->left) // whether x is on the left of it's parent, we change it to y
				x->parent->left = y;
			else
				x->parent->right = y;
			// putting x on y's left
			y->left = x;
			x->parent = y;
		}
	
		void	right_rotate(Node x)
		{
			Node	y;

			y = x->left;
			x->left = y->right;
			if (y && y->right != TNULL)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				this->root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}


		// if node's color is red, makes it black and vice-versa
		void	recolor(Node node) { node->color = (node->color == 0) ? 1 : 0; }

		// Need to understand
		void	rb_transplant(Node u, Node v)
		{
			if (u->parent == NULL)
				root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}
		
		void	fix_insert(Node node) // where node is the newly inserted node
		{
			Node	uncle; // Uncle is representing node->parent->parent->left/right
			
			while (node->parent->color == 1) // While the parent of our created node is red, the tree is unbalanced (Property 4)
			{
				if (node->parent == node->parent->parent->right) // If node's parent is on the right
				{
					uncle = node->parent->parent->left; // Setting the uncle
					if (uncle->color == 1) // If the uncle is red, the tree is unbalanced
					{
						// Flipping the uncle, parent and grandparent's color
						uncle->color = 0;
						node->parent->color = 0;
						node->parent->parent->color = 1;
						node = node->parent->parent;
					}
					else
					{
						// If the parent is red while the uncle is black or NULL
						if (node == node->parent->left) // If node is left child of parent and parent is right child of grandparent, must right_rotate
						{
							node = node->parent;
							right_rotate(node);
						}
						// If node is right child of parent and parent is right child of grandparent, left_rotate + color switch
						node->parent->color = 0;
						node->parent->parent->color = 1;
						left_rotate(node->parent->parent);
					}
				}
				else // If node's parent is on the left, same as the other but inverted side and rotation
				{
					uncle = node->parent->parent->right;
					if (uncle->color == 1)
					{
						uncle->color = 0;
						node->parent->color = 0;
						node->parent->parent->color = 1;
						node = node->parent->parent;
					}
					else
					{
						if (node == node->parent->right)
						{
							node = node->parent;
							left_rotate(node);
						}
						node->parent->color = 0;
						node->parent->parent->color = 1;
						right_rotate(node->parent->parent);
					}
				}
				if (node == root)
					break ;
			}
			root->color = 0; // Red-Black Tree's root must be black
		}

		void	fix_erase(Node node) //	need to determine what is node
		{
			Node	s;
			while (node != root && node->color == 0)
			{
				if (node == node->parent->left)
				{
					s = node->parent->right;
					if (s->color == 1) // If red, we need to recolor it + left rotating to help later
					{
						s->color = 0;
						node->parent->color = 1;
						left_rotate(node->parent);
						s = node->parent->right;
					}
					if (s->left->color == 0 && s->right->color == 0) // Makes a node black
					{
						s->color = 1;
						node = node->parent;
					}
					else
					{
						if (s->right->color == 0)
						{
							s->left->color = 0;
							s->color = 1;
							right_rotate(s);
							s = node->parent->right;
						}
						s->color = node->parent->color;
						node->parent->color = 0;
						s->right->color = 0;
						left_rotate(node->parent);
						node = root;
					}
				}
				else
				{
					s = node->parent->left;
					if (s->color == 1)
					{
						s->color = 0;
						node->parent->color = 1;
						right_rotate(node->parent);
						s = node->parent->left;
					}
					if (s->right->color == 0)
					{
						s->color = 1;
						node = node->parent;
					}
					else
					{
						if (s->left->color == 0) // to check if don't need to add && s->right->color == 0
						{
							s->right->color = 0;
							s->color = 1;
							left_rotate(s);
							s = node->parent->left;
						}
						s->color = node->parent->color;
						node->parent->color = 0;
						s->left->color = 0;
						right_rotate(node->parent);
						node = root;
					}
				}
			}
			node->color = 0;
		}

		Node searchEngine(Key const &key, Node node, Comp compare) const
		{
			if (node == TNULL)
				return (NULL);
			if (key == node->data.first)
				return (node);
			if (compare(key, node->data.first))
				return (searchEngine(key, node->left, compare));
			else
				return (searchEngine(key, node->right, compare));
		}

		Node lower_bound_engine(Key const &key, Comp compare) const
		{
			Node	current = root;
			Node	prev = TNULL;

			while (current != TNULL)
			{
				if (!compare(current->data.first, key))
				{
					prev = current;
					current = current->left;
				}
				else
					current = current->right;
			}
			return (prev);
		}

		Node upper_bound_engine(Key const &key, Comp compare) const
		{
			Node	current = root;
			Node	prev = TNULL;

			while (current != TNULL)
			{
				if (compare(key, current->data.first))
				{
					prev = current;
					current = current->left;
				}
				else
					current = current->right;
			}
			
			return (prev);
		}

		bool	erase_engine(Comp compare, Key key)
		{
			int		y_color;
			Node	node = this->root;
			Node	x;
			Node	y;
			Node	z = TNULL;

			// Looking for the node
			while (node != TNULL)
			{
				if (node->data.first == key)
				{
					z = node;
					break ;
				}
				// Key comparison, if < => Go left, if > => Go right
				if (compare(node->data.first, key))
					node = node->right;
				else
					node = node->left;
			}
			// Return if the key don't exist
			if (z == TNULL)
				return (false);
			
			// Deleting the node
			y = z;
			y_color = y->color;
			if (z->left == TNULL)
			{
				x = z->right;
				rb_transplant(z, z->right);
			}
			else if (z->right == TNULL)
			{
				x = z->left;
				rb_transplant(z, z->left);
			}
			else
			{
				y = minimum(z->right);
				y_color = y->color;
				x = y->right;
				if (y->parent == z)
					x->parent = y;
				else
				{
					rb_transplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				rb_transplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}
			alloc.deallocate(z, 1);
			if (y_color == 0) // If the node deleted is black, then it need to be fixed
				fix_erase(x);
			return (true);
		}

	public:
		void	destroy_tree(Node node)
		{
			if (node && node != TNULL)
			{
				if (node->left && node->left != TNULL)
					destroy_tree(node->left);
				if (node->right && node->right != TNULL)
					destroy_tree(node->right);
				this->alloc.deallocate(node, 1);
			}
		}

		void	destroy_tnull()
		{
			this->alloc.deallocate(TNULL, 1);
			TNULL = NULL;
		}

		RedBlackTree(compare c) : comp(c)
		{
			TNULL = alloc.allocate(1);
			TNULL->color = 0;
			TNULL->left = NULL;
			TNULL->right = NULL;
			root = TNULL;
		}
		
		~RedBlackTree() { }

		s_tree<Key, T>	*insert(pair_type const &pair)
		{
			// Initializing new node
			Node	node = alloc.allocate(1);
			
			node->parent = NULL;
			this->alloc_pair.construct(&node->data, pair);
			node->left = TNULL;
			node->right = TNULL;
			node->color = 1;
			Node	y = NULL;
			Node	x = this->root;
			
			while (x != TNULL) // Searching the value with comparison
			{
				y = x;
				if (node->data.first == x->data.first)
				{
					alloc.deallocate(node, 1);
					return (NULL);
				}
				if (comp(node->data, x->data))
					x = x->left;
				else
					x = x->right;
			}
			
			node->parent = y; // Setting the parent
			if (y == NULL) // If y == NULL, then it means it didn't entered the while loop, therefore our tree is empty
				root = node;
			else if (comp(node->data, y->data)) // Setting where our node is supposed to go
				y->left = node;
			else
				y->right = node;
			
			if (node->parent == NULL) // If node is the root, then it don't need to be balanced but the root must be black
			{
				node->color = 0;
				return (node);
			}
			if (node->parent->parent == NULL) // If node is near the root, it don't need to be balanced
				return (node);
			Node copy = node;
			this->fix_insert(node);
			return (copy);
		}


		// Return the lowest value of the tree
		Node	minimum(Node node) const
		{
			if (root == TNULL || root == NULL)
				return (TNULL);
			while (node->left != TNULL)
				node = node->left;
			return (node);
		}

		// Return the highest value of the tree
		Node	maximum(Node node, bool end = false) const
		{
			if (root == TNULL || root == NULL)
				return (TNULL);
			while (node->right != TNULL)
				node = node->right;
			if (end)
				node = node->right;
			return (node);
		}

		Node	search(Key const &key) const { Comp compare; return (searchEngine(key, this->root, compare)); }
		bool	erase(Key const &key) { Comp compare; return (erase_engine(compare, key)); }

		Node	lower_bound(Key const &key) const { Comp compare; return (lower_bound_engine(key, compare)); }
		Node	upper_bound(Key const &key) const { Comp compare; return (upper_bound_engine(key, compare)); }

		Node	&getRoot() { return (this->root); }

		size_t	max_size() const { return (this->alloc.max_size()); }

		Node	get_tnull() const { return (this->TNULL); }
};

#endif
