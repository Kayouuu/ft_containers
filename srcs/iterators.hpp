/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:32:41 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/14 12:03:15 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

#include "ft_containers.hpp"

namespace ft
{
	template <class T>
	struct iterator_traits
	{
		typedef typename T::value_type            value_type;
		typedef typename T::difference_type       difference_type;
		typedef typename T::iterator_category     iterator_category;
		typedef typename T::pointer               pointer;
		typedef typename T::reference             reference;
	};
	template <class T>
	struct iterator_traits<T*>
	{
		typedef T                          		value_type;
		typedef long int						difference_type;
		typedef std::random_access_iterator_tag iterator_category; // Mandatory to use the std tag, otherwise STL algorithms wouldn't work 
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
			Iter	current =  Iter();
		public:
			// Member types
			typedef Iter    iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category   iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type          value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type      difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer				pointer;
			typedef	typename ft::iterator_traits<Iter>::reference			reference;

			// Constructors
			reverse_iterator() { } // TOCHECK else Iter current = Iter(); in protected field
			explicit	reverse_iterator(iterator_type x) { this->current = x; }
			template<class U>
			reverse_iterator(reverse_iterator<U> const &other) { *this = other; }
			template<class U>
			reverse_iterator	&operator=(reverse_iterator<U> const &other) { this->current = other.base(); return (*this); }
			~reverse_iterator() { }
			
			iterator_type	base() const { return (this->current); }
			reference		operator*() const { Iter tmp = this->current; return (*--tmp); }
			pointer			operator->() const { return (&(operator*())); } // TOCHECK
			
			reference 			operator[](difference_type n) const { return (*(this->current + n)); }
			reverse_iterator&	operator++() { --this->current; return (*this); }
			reverse_iterator&	operator--() { ++this->current; return (*this); }
			reverse_iterator	operator++(int) { reverse_iterator tmp = *this; ++(*this); return (tmp); }
			reverse_iterator	operator--(int) { reverse_iterator tmp = *this; --(*this); return (tmp); }
			reverse_iterator	operator+(difference_type n) const { return (reverse_iterator(this->base() - n)); }
			reverse_iterator	operator-(difference_type n) const { return (reverse_iterator(this->base() + n)); }
			reverse_iterator&	operator+=(difference_type n) { this->current = &(*this->current) - n; return (*this); } // TOFIX For const, better to call a copy constructor of _current - n
			reverse_iterator&	operator-=(difference_type n) { this->current = &(*this->current) + n; return (*this); }
			
	};
	// TOCHECK reverse_iterator avec const
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
					const reverse_iterator<Iter>& it ) { return (reverse_iterator<Iter>(it.base() - n)); } // TOCHECK
	template< class Iterator >
	typename reverse_iterator<Iterator>::difference_type
		operator-(	const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs ) { return (rhs.base() - lhs.base()); }


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
			RandomAccessIterator() : _ptr(NULL) { }; // TOCHECK
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
			RandomAccessIterator	operator+(difference_type n) { return (RandomAccessIterator(this->_ptr + n)); }
			RandomAccessIterator	operator-(difference_type n) { return (RandomAccessIterator(this->_ptr - n)); }
			RandomAccessIterator	&operator[](difference_type pos) { return *(this->_ptr + n); }

			// friend	RandomAccessIterator	operator+(RandomAccessIterator const &lhs, RandomAccessIterator const &rhs);
			// friend	RandomAccessIterator	operator-(RandomAccessIterator const &lhs, RandomAccessIterator const &rhs);
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
	template <class T, typename Cont>
	typename RandomAccessIterator<T, Cont>::difference_type	operator-(RandomAccessIterator<T, Cont> const &lhs, RandomAccessIterator<T, Cont> const &rhs) { return (lhs.base() - rhs.base()); }
}

#endif