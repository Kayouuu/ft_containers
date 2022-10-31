/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:17:30 by psaulnie          #+#    #+#             */
/*   Updated: 2022/10/31 16:30:59 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

#include "stack/stack.hpp"

namespace	ft
{
	// TOCHECK Need to check if it's working
	template<class T, class Container>
	class stack;
	
	// TODO
	template<class T>
	class vector;

	// TODO
	template< class Iter >
	struct iterator_traits;
	template< class T >
	struct iterator_traits<T*>;
	template< class T >
	struct iterator_traits<const T*>;

	template< class Iter >
	class reverse_iterator;

	template< bool B, class T = void >
	struct enable_if;

	template< class T >
	struct is_integral;

	// equal and/or lexicographical_compare

	template<class T1, class T2>
	struct pair;

	template< class T1, class T2 >
	std::pair<T1, T2> make_pair( T1 t, T2 u );

	template<class T>
	class	RandomAccessIterator
	{
		private:
			pointer	_ptr;
	};
}

#endif