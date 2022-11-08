/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:17:30 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/07 15:54:16 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

// #include "stack/stack.hpp"
#include "vector/vector.hpp"
#include "iterators.hpp"
#include "is_integral.hpp"

namespace	ft
{
	// // TOCHECK Need to check if it's working
	// template<class T, class Container>
	// class stack;
	
	// TODO
	template<class T, class Allocator>
	class vector;

	template<bool B, class T = void>
	struct enable_if { };

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	// // equal and/or lexicographical_compare

	// template<class T1, class T2>
	// struct pair;

	// template< class T1, class T2 >
	// std::pair<T1, T2> make_pair( T1 t, T2 u );
}

#endif