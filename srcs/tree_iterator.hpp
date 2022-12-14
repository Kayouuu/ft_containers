/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:38:52 by psaulnie          #+#    #+#             */
/*   Updated: 2022/12/12 14:29:13 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "tree.hpp"

namespace ft
{
	template< typename Key, typename U, typename T, typename Cont, typename Tree>
	class	RBTreeIterator
	{
		private:
			// Return the lowest value of the tree
			s_tree<Key, U>	*minimum(s_tree<Key, U>	*node)
			{
				while (node->left != NULL && node->left != TNULL)
					node = node->left;
				return (node);
			}

			// Return the highest value of the tree
			s_tree<Key, U>	*maximum(s_tree<Key, U>	*node)
			{
				while (node->right != TNULL && node->right != NULL)
					node = node->right;
				return (node);
			}
		public:
			typedef typename Tree::pair_type							value_type;
			typedef typename Tree::pair_type*							pointer;
			typedef typename Tree::pair_type&							reference;
			typedef	typename ft::iterator_traits<T*>::pointer			pointer_node;
			typedef	typename ft::iterator_traits<T*>::reference			reference_node;
			typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
			typedef	typename std::bidirectional_iterator_tag			iterator_category;

			// Constructors
			RBTreeIterator() : _ptr(NULL) { };
			RBTreeIterator(pointer_node ptr, s_tree<Key, U> *tnull, pointer_node end_node) : _ptr(ptr), end_node(end_node), TNULL(tnull)  { };
			RBTreeIterator(RBTreeIterator const &copy) { *this = copy; };

			template <class Key2, class U2, class Iter>
			RBTreeIterator(RBTreeIterator<Key2, U2, Iter, typename ft::enable_if<ft::is_same<Iter, typename Cont::pointer>::value, Cont >::type, Tree> const &copy) { *this = copy; }
			
			RBTreeIterator	&operator=(RBTreeIterator const &copy)
			{
				_ptr = copy._ptr;
				end_node = copy.end_node;
				TNULL = copy.TNULL;
				return (*this);
			};
			operator RBTreeIterator<Key, U, const T, Cont, Tree> () const { return (RBTreeIterator<Key, U, const T, Cont, Tree>(this->_ptr)); } // TOCHECK Need to understand this line, used to do the conversion between const and non-const
			// Destructor
			~RBTreeIterator() { };

			pointer	base() const { return (this->_ptr->data); }
			// Operator overload
			reference		operator*() const { return (_ptr->data); }
			pointer			operator->() const { return (&(_ptr->data)); }
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
			s_tree<Key, U>	*TNULL;

			bool	is_left_child(s_tree<Key, U> *node)
			{
				if (node && node->parent && node->parent->left)
					return (node == node->parent->left);
				return (false);
			}
			
			pointer_node	next_iter(s_tree<Key, U> *node)
			{
				if (node && node->right && node->right != TNULL)
				{
					node = node->right;
					s_tree<Key, U> *cursor = node;
					if (cursor == TNULL)
						return (NULL);
					while (cursor->left && cursor->left != TNULL)
						cursor = cursor->left;
					return (cursor);
				}
				else
				{
					s_tree<Key, U> *p = node->parent;
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

			pointer_node	prev_iter(s_tree<Key, U> *node)
			{
				if (node == TNULL || node == NULL)
						return (end_node);
				if (node && node->left && node->left != TNULL)
				{
					node = node->left;
					s_tree<Key, U> *cursor = node;
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
					s_tree<Key, U> *p = node->parent;
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
				// s_tree<Key, U>	*node2 = node;
				// while (is_left_child(node2))
				// 	node2 = node2->parent;
				// return (node2->parent);
			}

			friend bool operator==(RBTreeIterator const &a, RBTreeIterator const &b) // TOCHECK const & non-const ?
			{
				return (a._ptr == b._ptr);
				// if (a._ptr != a.TNULL)
				// 	return (a._ptr->data == b._ptr->data);
				// return (true);
			}
			
			friend bool	operator!=(RBTreeIterator const &a, RBTreeIterator const &b) { return (!(a == b)); }
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