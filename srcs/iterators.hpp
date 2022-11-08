/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:32:41 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/08 11:21:36 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP

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
		typedef T                          value_type;
		typedef ptrdiff_t                  difference_type; // TOCHECK
		typedef std::random_access_iterator_tag iterator_category; // TOCHECK Mandatory to use the std tag, otherwise STL algorithms wouldn't work 
		typedef T*                         pointer;
		typedef T&                         reference;
	};
	template< class T >
	struct iterator_traits<const T*>
	{
		typedef const T                          value_type;
		typedef ptrdiff_t                  difference_type; // TOCHECK
		typedef std::random_access_iterator_tag iterator_category; // TOCHECK Mandatory to use the std tag, otherwise STL algorithms wouldn't work
		typedef const T*                         pointer;
		typedef const T&                         reference;
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
			reverse_iterator() { this->it(); } // TOCHECK else Iter current = Iter(); in protected field
			explicit	reverse_iterator(iterator_type x) { this->current = x; }
			template<class U>
			reverse_iterator(reverse_iterator<U> const &other) { *this = other; }
			template<class U>
			reverse_iterator	&operator=(reverse_iterator<U> const &other) { this->current = other.current; return (*this); }
			~reverse_iterator() { }
			
			iterator_type	base() const { return (this->current); }
			reference		operator*() const { Iter tmp = this->current; return (*--tmp); }
			pointer			operator->() const { return (&(operator*())); } // TOCHECK
			
			reference 			operator[](difference_type n) const { return (this->base()[n - 1]); }
			reverse_iterator&	operator++() { --this->current; return (*this); }
			reverse_iterator&	operator--() { ++this->current; return (*this); }
			reverse_iterator	operator++(int) { reverse_iterator tmp = *this; ++(*this); return (tmp); }
			reverse_iterator	operator--(int) { reverse_iterator tmp = *this; --(*this); return (tmp); }
			reverse_iterator	operator+(difference_type n) const { return (reverse_iterator(&(*this->base()) - n)); }
			reverse_iterator	operator-(difference_type n) const { return (reverse_iterator(&(*this->base()) + n)); }
			reverse_iterator&	operator+=(difference_type n) { this->current = &(*this->current) - n; return (*this); } // TOFIX For const, better to call a copy constructor of _current - n
			reverse_iterator&	operator-=(difference_type n) { this->current = &(*this->current) + n; return (*this); }
			
	};

	template< class Iterator1, class Iterator2 >
	bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
                	 const ft::reverse_iterator<Iterator2>& rhs ) { return (lhs.base() == rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
                	 const ft::reverse_iterator<Iterator2>& rhs ) { return (lhs.base() != rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
                	 const ft::reverse_iterator<Iterator2>& rhs ) { return (lhs.base() < rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
                	 const ft::reverse_iterator<Iterator2>& rhs ) { return (lhs.base() <= rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
                	 const ft::reverse_iterator<Iterator2>& rhs ) { return (lhs.base() > rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
                	 const ft::reverse_iterator<Iterator2>& rhs ) { return (lhs.base() >= rhs.base()); }
	template< class Iter >
	reverse_iterator<Iter>
		operator+(	typename reverse_iterator<Iter>::difference_type n,
					const reverse_iterator<Iter>& it ) { return (reverse_iterator<Iter>(it.base() - n)); }
	template< class Iterator >
	typename reverse_iterator<Iterator>::difference_type
		operator-(	const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs ) { return (rhs.base() - lhs.base()); }

	
	template<typename T>
	class	RandomAccessIterator
	{
		public:
			// TODO Use ft::iterator_traits ?
			typedef T		value_type;
			typedef	T*		pointer;
			typedef	T&		reference;
			typedef long int	difference_type;
			typedef	std::random_access_iterator_tag	iterator_category;
			
			// Constructors
			RandomAccessIterator() { }; // TOCHECK
			RandomAccessIterator(pointer ptr) : _ptr(ptr) { };
			RandomAccessIterator(RandomAccessIterator const &copy) { *this = copy; };
			RandomAccessIterator	&operator=(RandomAccessIterator const &copy)
			{
				_ptr = copy._ptr;
				return (*this);
			};
			// Destructor
			~RandomAccessIterator() { };

			// Operator overload
			reference	operator*() const { return (*_ptr); }
			pointer		operator->() { return (_ptr); }
			RandomAccessIterator	&operator++() { _ptr++; return (*this); }
			RandomAccessIterator	operator++(int) { RandomAccessIterator tmp = *this; ++(*this); return (tmp); }
			RandomAccessIterator	&operator--() { _ptr--; return (*this); }
			RandomAccessIterator	operator--(int) { RandomAccessIterator tmp = *this; --(*this); return (tmp); }
			RandomAccessIterator	&operator+=(RandomAccessIterator const &rhs) { this->_ptr += rhs._ptr; return (*this); }
			RandomAccessIterator	&operator-=(RandomAccessIterator const &rhs) { this->_ptr -= rhs._ptr; return (*this); }
			RandomAccessIterator	operator+(RandomAccessIterator const &rhs) { RandomAccessIterator tmp = *this; return (tmp += rhs); }
			RandomAccessIterator	operator-(RandomAccessIterator const &rhs) { RandomAccessIterator tmp = *this; return (tmp -= rhs); }
			RandomAccessIterator	&operator[](difference_type pos) { return (this->_ptr[pos]); }
			friend	bool	operator==(RandomAccessIterator const &a, RandomAccessIterator const &b) { return (a._ptr == b._ptr); } // TOFX Put outside randomaccessiterator class
			friend	bool	operator!=(RandomAccessIterator const &a, RandomAccessIterator const &b) { return (a._ptr != b._ptr); }
			friend	bool	operator>(RandomAccessIterator const &a, RandomAccessIterator const &b) { return (a._ptr > b._ptr); }
			friend	bool	operator<(RandomAccessIterator const &a, RandomAccessIterator const &b) { return (a._ptr < b._ptr); }
			friend	bool	operator>=(RandomAccessIterator const &a, RandomAccessIterator const &b) { return (a._ptr >= b._ptr); }
			friend	bool	operator<=(RandomAccessIterator const &a, RandomAccessIterator const &b) { return (a._ptr <= b._ptr); }
			friend	RandomAccessIterator	operator+(RandomAccessIterator const &lhs, RandomAccessIterator const &rhs) { lhs += rhs; return (lhs); }
			friend	RandomAccessIterator	operator-(RandomAccessIterator const &lhs, RandomAccessIterator const &rhs) { lhs += rhs; return (lhs); }
		private:
			pointer	_ptr;
	};
}

#endif