/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:12:53 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/03 14:07:53 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"

// Constructor
template<class T, class Container>
stack::stack(Container const &cont = Container()) { }

template<class T, class Container>
stack::stack(stack const &copy) { *this = copy; }

template<class T, class Container>
stack	&stack::operator=(stack const &copy)
{
	_container = copy._container;
	return (*this);
}

// Destructor
template<class T, class Container>
stack::~stack() { }

//	Element access
template<class T, class Container>
const_reference	stack::top() const
{
	// TODO verifier si on doit le proteger
	return (_container.back());
}

// Capacity
template<class T, class Container>
bool	stack::empty() const
{
	// TODO verifier si on doit le proteger
	return (_container.empty());
}

template<class T, class Container>
size_type	stack::size() const
{
	// TODO verifier si on doit le proteger
	return (_container.size());
}

// Modifiers
template<class T, class Container>
void	stack::push(const value_type &value)
{
	// TODO verifier si on doit le proteger
	_container.push_back(value);
}

template<class T, class Container>
void	stack::pop()
{
	// TODO verifier si on doit le proteger
	_container.pop_back();
}

// Non-member functions
template<class T, class Container>
bool operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return (lhs._container == rhs._container);
}

template< class T, class Container >
bool operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return (lhs._container != rhs._container);
}

template< class T, class Container >
bool operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return (lhs._container < rhs._container);
}

template< class T, class Container >
bool operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return (lhs._container <= rhs._container);
}

template< class T, class Container >
bool operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return (lhs._container > rhs._container);
}

template< class T, class Container >
bool operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
{
	return (lhs._container >= rhs._container);
}
