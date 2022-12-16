/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:38:52 by psaulnie          #+#    #+#             */
/*   Updated: 2022/12/16 17:03:09 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "pair.hpp"
#include "tree.hpp"

namespace ft
{
	template< class Pair, class Node, bool is_const>
	class	RBTreeIterator
	{
		private:
			// Return the lowest value of the tree
			Node	minimum(Node node)
			{
				while (node->left != NULL && node->left != TNULL)
					node = node->left;
				return (node);
			}

			// Return the highest value of the tree
			Node	maximum(Node node)
			{
				while (node->right != TNULL && node->right != NULL)
					node = node->right;
				return (node);
			}
		public:
			typedef Pair                                          				value_type;
			typedef ptrdiff_t													difference_type;
			typedef typename ft::chooseConst<is_const, Pair, const Pair>::type	&reference;
			typedef	typename ft::chooseConst<is_const, Pair, const Pair>::type	*pointer;
			typedef Node														*pointer_node;
			typedef Node														&reference_node;
			typedef	typename std::bidirectional_iterator_tag					iterator_category;

			// Constructors
			RBTreeIterator() : _ptr(NULL) { };
			RBTreeIterator(pointer_node ptr, pointer_node tnull, pointer_node end_node) : _ptr(ptr), end_node(end_node), TNULL(tnull)  { };
			RBTreeIterator(RBTreeIterator const &copy) { *this = copy; };
			
			RBTreeIterator	&operator=(RBTreeIterator const &copy)
			{
				_ptr = copy._ptr;
				end_node = copy.end_node;
				TNULL = copy.TNULL;
				return (*this);
			};
			operator RBTreeIterator<Pair, Node, true>() const { return (RBTreeIterator<Pair, Node, true>(this->_ptr, this->TNULL, this->end_node)); } // TOCHECK Need to understand this line, used to do the conversion between const and non-const
			// Destructor
			~RBTreeIterator() { };

			pointer						base() const { return (this->_ptr->data); }
			pointer_node			 	node() const { return (this->_ptr); }
			pointer_node			 	get_end_node() const { return (this->end_node); }
			pointer_node			 	get_TNULL() const { return (this->TNULL); }
			// Operator overload
			reference					operator*() const { return ((_ptr->data)); }
			pointer						operator->() const { return (&(_ptr->data)); }
	
			RBTreeIterator	&operator++()
			{
				_ptr = next_iter(_ptr);
				return (*this);
			}
			RBTreeIterator	operator++(int) { RBTreeIterator tmp = *this; ++(*this); return (tmp); }
			RBTreeIterator	&operator--()
			{
				_ptr = prev_iter(_ptr);
				return (*this);
			}
			RBTreeIterator	operator--(int) { RBTreeIterator tmp = *this; --(*this); return (tmp); }

		private:
			pointer_node	_ptr;
			pointer_node	end_node;
			pointer_node	TNULL;

			// bool	is_left_child(T *node)
			// {
			// 	if (node && node->parent && node->parent->left)
			// 		return (node == node->parent->left);
			// 	return (false);
			// }
			
			pointer_node	next_iter(Node *node)
			{
				if (node && node->right && node->right != TNULL)
				{
					node = node->right;
					Node *cursor = node;
					if (cursor == TNULL)
						return (NULL);
					while (cursor->left && cursor->left != TNULL)
						cursor = cursor->left;
					return (cursor);
				}
				else
				{
					Node *p = node->parent;
					while (p && p != TNULL && node == p->right)
					{
						node = p;
						p = p->parent;
					}
					node = p;
					if (node == NULL)
						return (TNULL);
				}
				return (node);
				// if (node == end_node)
				// 	return (node->right);
				// if (node->right != NULL && node->right != TNULL)
				// 	return (minimum(node->right));
				// while (node && node->parent && node->parent->left && !is_left_child(node))
				// 	node = node->parent;
				// return (node->parent);
			}

			pointer_node	prev_iter(Node *node)
			{
				if (node == TNULL || node == NULL)
						return (end_node);
				if (node && node->left && node->left != TNULL)
				{
					node = node->left;
					Node *cursor = node;
					if (cursor == NULL || cursor == TNULL)
						return (NULL); 
					while (cursor->right && cursor->right != TNULL)
					{
						cursor = cursor->right;
					}
					return (cursor);
				}
				else
				{
					Node *p = node->parent;
					while (p && p != TNULL && node == p->left)
					{
						node = p;
						p = p->parent;
					}
					node = p;
					if (node == NULL)
						return (TNULL);
				}
				return (node);
				// if (node->left != NULL && node->left != TNULL)
				// 	return (maximum(node->left));
				// T	*node2 = node;
				// while (is_left_child(node2))
				// 	node2 = node2->parent;
				// return (node2->parent);
			}


			friend bool operator==(RBTreeIterator const &a, RBTreeIterator const &b) { return (a._ptr == b._ptr); }
			template <class T2>
			friend bool	operator==(RBTreeIterator<Pair, Node, false> const &a, RBTreeIterator<Pair, T2, true> const &b) { return (a == b); }
			
			friend bool	operator!=(RBTreeIterator const &a, RBTreeIterator const &b) { return (!(a == b)); }
			template <class T2>
			friend bool	operator!=(RBTreeIterator<Pair, Node, false> const &a, RBTreeIterator<Pair, T2, true> const &b) { return (!(a == b)); }
	};

	// template <class Key, class U, class T, typename Cont>
	// bool	operator==(RBTreeIterator<Key, U, T, Cont> const &a, RBTreeIterator<Key, U, T, Cont> const &b) { return (&*a._ptr->data.first == &*b._ptr->data.first && &*a._ptr->data.second == &*b._ptr->data.second); } // TODO
	// template <class Key, class U, class T, class T2, typename Cont>
	// bool	operator==(RBTreeIterator<Key, U, T, Cont> const &a, RBTreeIterator<Key, U, T2, Cont> const &b) { return (&*a._ptr->data.first == &*b._ptr->data.first && &*a._ptr->data.second == &*b._ptr->data.second); } // TODO

	// template <class Key, class U, class T, typename Cont>
	// bool	operator!=(RBTreeIterator<Key, U, T, Cont> const &a, RBTreeIterator<Key, U, T, Cont> const &b) { return (!(&*a == &*b)); }
	// template <class Key, class U, class T, class T2, typename Cont>
	// bool	operator!=(RBTreeIterator<Key, U, T, Cont> const &a, RBTreeIterator<Key, U, T2, Cont> const &b) { return (!(&*a == &*b)); }
}