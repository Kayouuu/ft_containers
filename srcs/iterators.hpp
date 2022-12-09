/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:32:41 by psaulnie          #+#    #+#             */
/*   Updated: 2022/12/09 17:29:42 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

#include "tree.hpp"

namespace ft
{
	template <class T>
	struct iterator_traits
	{
		typedef typename T::value_type			value_type;
		typedef typename T::difference_type		difference_type;
		typedef typename T::iterator_category	iterator_category;
		typedef typename T::pointer				pointer;
		typedef typename T::reference			reference;
	};
	template <class T>
	struct iterator_traits<T*>
	{
		typedef T                          		value_type;
		typedef long int						difference_type;
		typedef std::random_access_iterator_tag	iterator_category; // Mandatory to use the std tag, otherwise STL algorithms wouldn't work 
		typedef T*                        		pointer;
		typedef T&                         		reference;
	};
	template< class T >
	struct iterator_traits<const T*>
	{
		typedef const T							value_type;
		typedef long int						difference_type;
		typedef std::random_access_iterator_tag iterator_category; // Mandatory to use the std tag, otherwise STL algorithms wouldn't work
		typedef const T*						pointer;
		typedef const T&						reference;
	};
		
	template< class Iter >
	class reverse_iterator
	{
		protected:
			Iter	current;
		public:
			// Member types
			typedef Iter    iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category   iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type          value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type      difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer				pointer;
			typedef	typename ft::iterator_traits<Iter>::reference			reference;

			// Constructors
			reverse_iterator() { Iter	it; current = it; }
			explicit	reverse_iterator(iterator_type x): current(x) {};
			template<class U>
			reverse_iterator(reverse_iterator<U> const &other): current(other.base()) {};
			~reverse_iterator() { }
			
			iterator_type	base() const { return (this->current); }
			reference		operator*() const { Iter tmp = this->current; return (*--tmp); }
			pointer			operator->() const { return (&(operator*())); }
			
			reference 			operator[](difference_type n) const { return (this->current[-n - 1]); }
			reverse_iterator&	operator++() { --this->current; return (*this); }
			reverse_iterator&	operator--() { ++this->current; return (*this); }
			reverse_iterator	operator++(int) { reverse_iterator tmp(*this); --current; return (tmp); }
			reverse_iterator	operator--(int) { reverse_iterator tmp(*this); ++current; return (tmp); }
			reverse_iterator	operator+(difference_type n) const { return (reverse_iterator(this->base() - n)); }
			reverse_iterator	operator-(difference_type n) const { return (reverse_iterator(this->base() + n)); }
			reverse_iterator&	operator+=(difference_type n) { this->current -= n; return (*this); }
			reverse_iterator&	operator-=(difference_type n) { this->current += n; return (*this); }
			
	};
	template< class Iterator1, class Iterator2 >
	bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
						const ft::reverse_iterator<Iterator2>& rhs ) { return (lhs.base() == rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
						const ft::reverse_iterator<Iterator2>& rhs ) { return (lhs.base() != rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
						const ft::reverse_iterator<Iterator2>& rhs ) { return (lhs.base() > rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
						const ft::reverse_iterator<Iterator2>& rhs ) { return (lhs.base() >= rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
						const ft::reverse_iterator<Iterator2>& rhs ) { return (lhs.base() < rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
						const ft::reverse_iterator<Iterator2>& rhs ) { return (lhs.base() <= rhs.base()); }
	template< class Iter >
	reverse_iterator<Iter>
		operator+(	typename reverse_iterator<Iter>::difference_type n,
					const reverse_iterator<Iter>& it ) { return (reverse_iterator<Iter>(it.base() - n)); }
	template< class Iterator, class Iterator2 >
	typename reverse_iterator<Iterator>::difference_type
		operator-(	const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator2>& rhs ) { return (rhs.base() - lhs.base()); }


	template< typename T, typename Cont >
	class	RandomAccessIterator
	{
		public:
			typedef typename ft::iterator_traits<T*>::value_type			value_type;
			typedef	typename ft::iterator_traits<T*>::pointer			pointer;
			typedef	typename ft::iterator_traits<T*>::reference			reference;
			typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
			typedef	typename std::random_access_iterator_tag			iterator_category;

			// Constructors
			RandomAccessIterator() : _ptr(NULL) { };
			RandomAccessIterator(pointer ptr) : _ptr(ptr) { };
			RandomAccessIterator(RandomAccessIterator const &copy) { *this = copy; };
			RandomAccessIterator	&operator=(RandomAccessIterator const &copy)
			{
				_ptr = copy._ptr;
				return (*this);
			};
			operator RandomAccessIterator<const T, Cont> () const { return (RandomAccessIterator<const T, Cont>(this->_ptr)); } // TOCHECK Need to understand this line, used to do the conversion between const and non-const
			// Destructor
			~RandomAccessIterator() { };

			pointer	base() const { return (this->_ptr); }
			// Operator overload
			reference	operator*() const { return (*_ptr); }
			pointer		operator->() { return (_ptr); }
			RandomAccessIterator	&operator++() { _ptr++; return (*this); }
			RandomAccessIterator	operator++(int) { RandomAccessIterator tmp = *this; ++(*this); return (tmp); }
			RandomAccessIterator	&operator--() { _ptr--; return (*this); }
			RandomAccessIterator	operator--(int) { RandomAccessIterator tmp = *this; --(*this); return (tmp); }
			RandomAccessIterator	&operator+=(difference_type n) { this->_ptr += n; return (*this); }
			RandomAccessIterator	&operator-=(difference_type n) { this->_ptr -= n; return (*this); }
			RandomAccessIterator	operator+(difference_type n) const { return (RandomAccessIterator(this->_ptr + n)); }
			RandomAccessIterator	operator-(difference_type n) const { return (RandomAccessIterator(this->_ptr - n)); }
			reference				operator[](difference_type pos) const { return (*(this->_ptr + pos)); }
		private:
			pointer	_ptr;
	};

	template <class T, typename Cont>
	bool	operator==(RandomAccessIterator<T, Cont> const &a, RandomAccessIterator<T, Cont> const &b) { return (&*a == &*b); }
	template <class T, class T2, typename Cont>
	bool	operator==(RandomAccessIterator<T, Cont> const &a, RandomAccessIterator<T2, Cont> const &b) { return (&*a == &*b); }

	template <class T, typename Cont>
	bool	operator!=(RandomAccessIterator<T, Cont> const &a, RandomAccessIterator<T, Cont> const &b) { return (&*a != &*b); }
	template <class T, class T2, typename Cont>
	bool	operator!=(RandomAccessIterator<T, Cont> const &a, RandomAccessIterator<T2, Cont> const &b) { return (&*a != &*b); }
	
	template <class T, typename Cont>
	bool	operator>(RandomAccessIterator<T, Cont> const &a, RandomAccessIterator<T, Cont> const &b) { return (&*a > &*b); }
	template <class T, class T2, typename Cont>
	bool	operator>(RandomAccessIterator<T, Cont> const &a, RandomAccessIterator<T2, Cont> const &b) { return (&*a > &*b); }

	template <class T, typename Cont>
	bool	operator>=(RandomAccessIterator<T, Cont> const &a, RandomAccessIterator<T, Cont> const &b) { return (&*a >= &*b); }
	template <class T, class T2, typename Cont>
	bool	operator>=(RandomAccessIterator<T, Cont> const &a, RandomAccessIterator<T2, Cont> const &b) { return (&*a >= &*b); }

	template <class T, typename Cont>
	bool	operator<(RandomAccessIterator<T, Cont> const &a, RandomAccessIterator<T, Cont> const &b) { return (&*a < &*b); }
	template <class T, class T2, typename Cont>
	bool	operator<(RandomAccessIterator<T, Cont> const &a, RandomAccessIterator<T2, Cont> const &b) { return (&*a < &*b); }

	template <class T, typename Cont>
	bool	operator<=(RandomAccessIterator<T, Cont> const &a, RandomAccessIterator<T, Cont> const &b) { return (&*a <= &*b); }
	template <class T, class T2, typename Cont>
	bool	operator<=(RandomAccessIterator<T, Cont> const &a, RandomAccessIterator<T2, Cont> const &b) { return (&*a <= &*b); }

	template <class T, typename Cont>
	RandomAccessIterator<T, Cont>	operator+(typename RandomAccessIterator<T, Cont>::difference_type n, RandomAccessIterator<T, Cont> const &rhs) { return (RandomAccessIterator<T, Cont>(rhs + n)); }
	template <class T, class T2, typename Cont>
	RandomAccessIterator<T, Cont>	operator+(typename RandomAccessIterator<T, Cont>::difference_type n, RandomAccessIterator<T2, Cont> const &rhs) { return (RandomAccessIterator<T, Cont>(rhs + n)); }

	template <class T, typename Cont>
	typename RandomAccessIterator<T, Cont>::difference_type	operator-(RandomAccessIterator<T, Cont> const &lhs, RandomAccessIterator<T, Cont> const &rhs) { return (lhs.base() - rhs.base()); }
	template <class T, class T2, typename Cont>
	typename RandomAccessIterator<T, Cont>::difference_type	operator-(RandomAccessIterator<T, Cont> const &lhs, RandomAccessIterator<T2, Cont> const &rhs) { return (lhs.base() - rhs.base()); }

	// TODO
	template< typename Key, typename U, typename T, typename Cont, typename Tree >
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
			RBTreeIterator	&operator=(RBTreeIterator const &copy)
			{
				_ptr = copy._ptr;
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
				{
					// if ( != TNULL)
						return (end_node);
					// return (node);
				}
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

#endif
