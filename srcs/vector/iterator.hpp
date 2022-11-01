/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:20:01 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/01 12:08:13 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

class	RandomAccessIterator
{
	public:
		// TODO Use ft::iterator_traits
		typedef int		value_type;
		typedef	int*	pointer;
		typedef	int&	reference;
		
		// Constructors
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
		friend bool	operator==(RandomAccessIterator const &a, RandomAccessIterator const &b) { return (a._ptr == b._ptr); }
		friend bool	operator!=(RandomAccessIterator const &a, RandomAccessIterator const &b) { return (a._ptr == b._ptr); }
	private:
		pointer	_ptr;
};

class	ConstRandomAccessIterator
{
	public:
		// TODO Use ft::iterator_traits
		typedef int		value_type;
		typedef	int*	pointer;
		typedef	int&	reference;
		
		// Constructors
		ConstRandomAccessIterator(pointer ptr) : _ptr(ptr) { };
		ConstRandomAccessIterator(ConstRandomAccessIterator const &copy) : _ptr(copy._ptr) { };
		ConstRandomAccessIterator	&operator=(ConstRandomAccessIterator const &copy) { return (*this); };
		// Destructor
		~ConstRandomAccessIterator() { };

		// Operator overload
		reference	operator*() const { return (*_ptr); }
		pointer		operator->() { return (_ptr); }
		friend bool	operator==(ConstRandomAccessIterator const &a, ConstRandomAccessIterator const &b) { return (a._ptr == b._ptr); }
		friend bool	operator!=(ConstRandomAccessIterator const &a, ConstRandomAccessIterator const &b) { return (a._ptr == b._ptr); }
	private:
		const pointer	_ptr;
};

#endif