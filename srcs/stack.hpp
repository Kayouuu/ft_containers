/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:20:42 by psaulnie          #+#    #+#             */
/*   Updated: 2022/12/14 15:03:29 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace	ft
{
	template<
		class T,
		class Container = ft::vector<T>
	>
	class stack
	{
		protected:
			Container	c;
		public:
			typedef				Container					container_type;
			typedef typename	Container::value_type		value_type;
			typedef	typename	Container::size_type		size_type;
			typedef	typename	Container::reference		reference;
			typedef	typename	Container::const_reference	const_reference;
			// Constructors
			explicit stack(Container const &cont = Container()) { c = cont; }
			stack(stack const &copy) { *this = copy; }
			stack	&operator=(stack const &copy)
			{
				
				c = copy.c;
				return (*this);
			}
			
			// Destructor
			~stack() { };
			
			// Element access
			const_reference	top() const { return (c.back()); }

			// Capacity
			bool		empty() const { return (c.empty()); }
			size_type	size() const { return (c.size()); }

			// Modifiers
			void	push(const value_type &value) 
			{
				c.push_back(value);
			}
			void	pop()
			{
				c.pop_back(); 
			}

		// Non member-functions / Operator overloading

		friend bool operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return (lhs.c == rhs.c); }
		friend bool operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return (lhs.c != rhs.c); }
		friend bool operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return (lhs.c < rhs.c); }
		friend bool operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return (lhs.c <= rhs.c); }
		friend bool operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return (lhs.c > rhs.c); }
		friend bool operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return (lhs.c >= rhs.c); }
	};


}
#endif