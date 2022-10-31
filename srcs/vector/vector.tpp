/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:47:23 by psaulnie          #+#    #+#             */
/*   Updated: 2022/10/31 14:44:03 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

// TODO Template?

vector::vector() 
{
	// TOCHECK
	this->_size = 0;
	this->_capacity = 0;
}

vector::vector(vector const &copy)
{
	if (*this != copy)
		*this = copy;
}

vector	&operator=(vector const &copy)
{
	// TODO Deep copy, do at the end
	return (*this);
}

explicit vector::vector(const Allocator& alloc)
{
	// TOCHECK ~Need to check if it's enough
	this->_alloc = alloc;
}

explicit vector::vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator())
{
	// TODO
}

template<class InputIt>
vector::vector(InputIt first, InputIt last, const Allocator& alloc = Allocator())
{
	// TODO
}

// Destructor
~vector::vector()
{
	// TODO
}

// Assign
void vector::assign(size_type count, const T& value)
{
	// TODO
}

template<class InputIt>
void vector::assign(InputIt first, InputIt last)
{
	// TODO
}

// Get_allocator
allocator_type vector::get_allocator() const
{
	// TOCHECK Need to check if it's correct
	return (this->_alloc);
}

// Element access
reference	vector::at(size_type pos)
{
	// TOFIX Use self-made out_of_range exception
	if (!(pos < this->_size))
		throw	std::out_of_range;
	return (this->_arr[pos]);
}

const_reference	vector::at(size_type pos) const
{
	// TOFIX Use self-made out_of_range exception
	if (!(pos < this->_size))
		throw	std::out_of_range;
	return (this->_arr[pos]);
}

reference	&vector::operator[](size_type pos) { return (this->_arr[pos]); }

const_reference	&vector::operator[](size_type pos) const;

reference	vector::front()
{
	// TOCHECK
	// if (this->empty())
	// 	return ();
	return (this->_arr[0]);
}

const_reference	vector::front() const
{
	// TOCHECK
	// if (this->empty())
	// 	return ();
	return (this->_arr[0]);
}

reference	vector::back()
{
	// TOCHECK
	// if (this->empty())
	// 	return ();
	return (this->_arr[this->_size - 1]);
}

const_reference	vector::back() const
{
	// TOCHECK
	// if (this->empty())
	// 	return ();
	return (this->_arr[this->_size - 1]);
}

T	*vector::data()
{
	// TOCHECK
	if (this->_size == 0)
		return (NULL);
	return (this->_arr);
}

const T	*vector::data() const
{
	// TOCHECK
	if (this->_size == 0)
		return (NULL);
	return (this->_arr);
}

// Iterators
iterator		vector::begin()
{
	// TODO
}

const_iterator	vector::begin() const
{
	// TODO
}

iterator	vector::end()
{
	// TODO
}

const_iterator	vector::end() const
{
	// TODO
}

reverse_iterator	vector::rbegin()
{
	// TODO
}

const_reverse_iterator	vector::rbegin() const
{
	// TODO
}

reverse_iterator	vector::rend()
{
	// TODO
}

const_reverse_iterator	vector::rend() const
{
	// TODO
}

// Capacity
bool		vector::empty() const
{
	if (this->begin() == this->end())
		return (true);
	return (false);
}

size_type	vector::size() const { return (this->size); }

size_type	vector::max_size() const { return (this->_alloc.max_size()); }

void	vector::reserve(size_type new_cap)
{
	// TODO
}

size_type	vector::capacity() const { return (this->_capacity); }

// Modifiers
void		vector::clear()
{
	// TODO
}

iterator	vector::insert(const_iterator pos, const T &value)
{
	// TODO
}

iterator	vector::insert(const_iterator pos, size_type count, const T& value)
{
	// TODO
}

template<class InputIt>
iterator	vector::insert(const_iterator pos, InputIt first, InputIt last)
{
	// TODO
}

iterator	vector::erase(iterator pos)
{
	// TODO
}

iterator	vector::erase(iterator first, iterator last)
{
	// TODO
}

void		vector::push_back(const T& value)
{
	// TODO
}

void		vector::pop_back()
{
	// TODO
}

void		vector::resize(size_type count, T value = T())
{
	// TODO
}

void		vector::swap(vector &other)
{
	// TODO
}