/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:38:52 by psaulnie          #+#    #+#             */
/*   Updated: 2022/12/16 11:01:05 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "pair.hpp"
#include "tree.hpp"

namespace ft
{
	template< typename Key, typename Value, typename T, typename Pair, typename Tree>
	class	RBTreeIterator
	{
		private:
			// Return the lowest value of the tree
			T	*minimum(T	*node)
			{
				while (node->left != NULL && node->left != TNULL)
					node = node->left;
				return (node);
			}

			// Return the highest value of the tree
			T	*maximum(T	*node)
			{
				while (node->right != TNULL && node->right != NULL)
					node = node->right;
				return (node);
			}
		public:
			typedef T                                            		iterator_type;
			typedef Pair                                          		value_type;
			typedef ptrdiff_t                                       	difference_type;
			typedef Pair&                                           	reference;
			typedef const Pair&                                     	const_reference;
			typedef Pair*                                           	pointer;
			typedef const Pair*                                     	const_pointer;
			typedef	typename ft::iterator_traits<T*>::pointer			pointer_node;
			typedef	typename ft::iterator_traits<T*>::reference			reference_node;
			typedef	typename std::bidirectional_iterator_tag			iterator_category;

			// Constructors
			RBTreeIterator() : _ptr(NULL) { };
			RBTreeIterator(pointer_node ptr, T *tnull, pointer_node end_node) : _ptr(ptr), end_node(end_node), TNULL(tnull)  { };
			RBTreeIterator(RBTreeIterator const &copy) { *this = copy; };

			template<class U, class Z>
			RBTreeIterator(const RBTreeIterator<Key, Value, U, Z, Tree>& other, typename ft::enable_if<std::is_convertible<U, T>::value>::type* = 0) : _ptr(other.node()), end_node(other.end_node), TNULL(other.TNULL) { };
			// template <class Iter>
			// RBTreeIterator(RBTreeIterator<Pair, Iter, typename ft::enable_if<ft::is_same<Iter, typename Tree::pointer>::value >::type> const &copy) { *this = copy; }
			
			RBTreeIterator	&operator=(RBTreeIterator const &copy)
			{
				_ptr = copy._ptr;
				end_node = copy.end_node;
				TNULL = copy.TNULL;
				return (*this);
			};
			operator RBTreeIterator<Key, Value, Pair, const T, Tree> () const { return (RBTreeIterator<Key, Value, Pair, const T, Tree>(this->_ptr)); } // TOCHECK Need to understand this line, used to do the conversion between const and non-const
			// Destructor
			~RBTreeIterator() { };

			ft::pair<const Key, Value>	*base() const { return (this->_ptr->data); }
			pointer_node			 node() const { return (this->_ptr); }
			// Operator overload
			ft::pair<const Key, Value>	&operator*() const { return ((_ptr->data)); }
			ft::pair<const Key, Value>	*operator->() const { return (&_ptr->data); }
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
			pointer_node				_ptr;
			pointer_node				end_node;
			T	*TNULL;

			// bool	is_left_child(T *node)
			// {
			// 	if (node && node->parent && node->parent->left)
			// 		return (node == node->parent->left);
			// 	return (false);
			// }
			
			pointer_node	next_iter(T *node)
			{
				if (node && node->right && node->right != TNULL)
				{
					node = node->right;
					T *cursor = node;
					if (cursor == TNULL)
						return (NULL);
					while (cursor->left && cursor->left != TNULL)
						cursor = cursor->left;
					return (cursor);
				}
				else
				{
					T *p = node->parent;
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

			pointer_node	prev_iter(T *node)
			{
				if (node == TNULL || node == NULL)
						return (end_node);
				if (node && node->left && node->left != TNULL)
				{
					node = node->left;
					T *cursor = node;
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
					T *p = node->parent;
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
			friend bool	operator==(RBTreeIterator<Key, Value, T, Pair, Tree> const &a, RBTreeIterator<Key, Value, T2, Pair, Tree> const &b) { return (a == b); }
			
			friend bool	operator!=(RBTreeIterator const &a, RBTreeIterator const &b) { return (!(a == b)); }
			template <class T2>
			friend bool	operator!=(RBTreeIterator<Key, Value, T, Pair, Tree> const &a, RBTreeIterator<Key, Value, T2, Pair, Tree> const &b) { return (!(a == b)); }
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