/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:20:42 by psaulnie          #+#    #+#             */
/*   Updated: 2022/10/27 11:45:28 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include <vector>
#include "../ft_containers.hpp"

template<
	class T,
	class Container = std::vector<T> // remplacer par ft::vector<T>
>
class stack
{
	private:
		Container	_container;
	public:
		// Constructors
		explicit stack(Container const &cont = Container());
		stack(stack const &copy);
		stack	&operator=(stack const &copy);
		
		// Destructor
		~stack();
		
		// Element access
		T const	&top() const;

		// Capacity
		bool	empty() const;
		unsigned int	size() const;

		// Modifiers
		void	push(T const &value);
		void	pop();
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