/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:20:42 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/17 17:44:31 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"
#include "ft_containers.hpp"

namespace	ft
{
	template<
		class T,
		class Container = ft::vector<T>
	>
	class stack
	{
		private:
			Container	_container;
		public:
			typedef				Container					container_type;
			typedef typename	Container::value_type		value_type;
			typedef	typename	Container::size_type		size_type;
			typedef	typename	Container::reference		reference;
			typedef	typename	Container::const_reference	const_reference;
			// Constructors
			explicit stack(Container const &cont = Container()) { _container = cont; }
			stack(stack const &copy) { *this = copy; }
			stack	&operator=(stack const &copy)
			{
				
				_container = copy._container;
				return (*this);
			}
			
			// Destructor
			~stack() { };
			
			// Element access
			const_reference	top() const { return (_container.back()); }

			// Capacity
			bool		empty() const { return (_container.empty()); }
			size_type	size() const { return (_container.size()); }

			// Modifiers
			void	push(const value_type &value) 
			{
				_container.push_back(value);
			}
			void	pop()
			{
				_container.pop_back(); 
			}

		// Non member-functions / Operator overloading

		friend bool operator==(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return (lhs._container == rhs._container); }
		friend bool operator!=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return (lhs._container != rhs._container); }
		friend bool operator<(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return (lhs._container < rhs._container); }
		friend bool operator<=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return (lhs._container <= rhs._container); }
		friend bool operator>(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return (lhs._container > rhs._container); }
		friend bool operator>=(const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs) { return (lhs._container >= rhs._container); }
	};


}
#endif