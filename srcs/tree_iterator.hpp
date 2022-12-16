/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:38:52 by psaulnie          #+#    #+#             */
/*   Updated: 2022/12/16 14:57:55 by psaulnie         ###   ########.fr       */
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
			T	minimum(T	node)
			{
				while (node->left != NULL && node->left != TNULL)
					node = node->left;
				return (node);
			}

			// Return the highest value of the tree
			T	maximum(T	node)
			{
				while (node->right != TNULL && node->right != NULL)
					node = node->right;
				return (node);
			}
		public:
			typedef Pair                                          		value_type;
			typedef ptrdiff_t                                       	difference_type;
			typedef Pair&                                           	reference;
			typedef const Pair&                                     	const_reference;
			typedef Pair										*pointer;
			typedef const Pair									*const_pointer;
			typedef T													pointer_node;
			typedef T													&reference_node;
			typedef	typename std::bidirectional_iterator_tag			iterator_category;

			// Constructors
			RBTreeIterator() : _ptr(NULL) { };
			RBTreeIterator(pointer_node ptr, pointer_node tnull, pointer_node end_node) : _ptr(ptr), end_node(end_node), TNULL(tnull)  { };
			RBTreeIterator(RBTreeIterator const &copy) { *this = copy; };

			template<class U, class P>
			RBTreeIterator(const RBTreeIterator<Key, Value, U, P, Tree>& other) : _ptr(other.node()), end_node(other.get_end_node()), TNULL(other.get_TNULL()) { };
			
			RBTreeIterator	&operator=(RBTreeIterator const &copy)
			{
				_ptr = copy._ptr;
				end_node = copy.end_node;
				TNULL = copy.TNULL;
				return (*this);
			};
			operator RBTreeIterator<Key, Value, const T, Pair, Tree> () const { return (RBTreeIterator<Key, Value, const T, Pair, Tree>(this->_ptr)); } // TOCHECK Need to understand this line, used to do the conversion between const and non-const
			// Destructor
			~RBTreeIterator() { };

			pointer						base() const { return (this->_ptr->data); }
			pointer_node			 	node() const { return (this->_ptr); }
			pointer_node			 	get_end_node() const { return (this->end_node); }
			pointer_node			 	get_TNULL() const { return (this->TNULL); }
			// Operator overload
			reference					operator*() { return ((_ptr->data)); }
			const_reference				operator*() const { return ((_ptr->data)); }
			pointer						operator->() { return (&(_ptr->data)); }
			const_pointer				operator->() const { return (&(_ptr->data)); }
	
			RBTreeIterator	&operator++()
			{
				next_iter();
				return (*this);
			}
			RBTreeIterator	operator++(int) { RBTreeIterator tmp = *this; ++(*this); return (tmp); }
			RBTreeIterator	&operator--()
			{
				prev_iter();
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
			
			void	next_iter()
			{

				if (_ptr && _ptr->right && _ptr->right != TNULL)
				{
					_ptr = _ptr->right;
					T cursor = _ptr;
					if (cursor == TNULL)
					{
						_ptr = NULL;
						return ;
					}
					while (cursor->left && cursor->left != TNULL)
						cursor = cursor->left;
					_ptr = cursor;
				}
				else
				{
					T p = _ptr->parent;
					while (p && p != TNULL && _ptr == p->right)
					{
						_ptr = p;
						p = p->parent;
					}
					_ptr = p;
					if (_ptr == NULL)
						_ptr = TNULL;
				}
				// if (node == end_node)
				// 	return (node->right);
				// if (node->right != NULL && node->right != TNULL)
				// 	return (minimum(node->right));
				// while (node && node->parent && node->parent->left && !is_left_child(node))
				// 	node = node->parent;
				// return (node->parent);
			}

			void	prev_iter()
			{
				if (_ptr == TNULL || _ptr == NULL)
				{
					_ptr = end_node;
					return ;
				}
				if (_ptr && _ptr->left && _ptr->left != TNULL)
				{
					_ptr = _ptr->left;
					T cursor = _ptr;
					if (cursor == NULL || cursor == TNULL)
					{
						_ptr = NULL;
						return ;
					}
					while (cursor->right && cursor->right != TNULL)
					{
						cursor = cursor->right;
					}
					_ptr = cursor;
				}
				else
				{
					T p = _ptr->parent;
					while (p && p != TNULL && _ptr == p->left)
					{
						_ptr = p;
						p = p->parent;
					}
					_ptr = p;
					if (_ptr == NULL)
					{
						_ptr = TNULL;
						return ;
					}
				}
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