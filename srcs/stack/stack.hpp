/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:20:42 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/01 13:33:14 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include <vector>
#include "../ft_containers.hpp"

template<
	class T,
	class Container = ft::vector<T>
>
class stack
{
	private:
		typedef	Container	container_type;
		typedef typename Container::value_type	value_type;
		typedef	typename Container::size_type	size_type;
		typedef	typename Container::reference	reference;
		typedef	typename Container::const_reference	const_reference;
		Container	_container;
	public:
		// Constructors
		explicit stack(Container const &cont = Container());
		stack(stack const &copy);
		stack	&operator=(stack const &copy);
		
		// Destructor
		~stack();
		
		// Element access
		const_reference	top() const;

		// Capacity
		bool		empty() const;
		size_type	size() const;

		// Modifiers
		void	push(const value_type &value);
		void	pop();

		// Friend functions

		template<class T, class Container>
		friend bool operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

		template< class T, class Container >
		friend bool operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

		template< class T, class Container >
		friend bool operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

		template< class T, class Container >
		friend bool operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

		template< class T, class Container >
		friend bool operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

		template< class T, class Container >
		friend bool operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);
};

// Non member-functions / Operator overloading

template<class T, class Container>
bool operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

template< class T, class Container >
bool operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

template< class T, class Container >
bool operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

template< class T, class Container >
bool operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

template< class T, class Container >
bool operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

template< class T, class Container >
bool operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs);

#endif