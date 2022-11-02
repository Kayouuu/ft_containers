/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:17:30 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/02 09:47:20 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

// #include "stack/stack.hpp"
#include "vector/vector.hpp"

namespace	ft
{
	// // TOCHECK Need to check if it's working
	// template<class T, class Container>
	// class stack;
	
	// TODO
	template< class T, class Allocator >
	class vector;

    template <class T>
    struct iterator_traits
	{
        typedef typename T::value_type            value_type;
        typedef typename T::difference_type       difference_type;
        typedef typename T::iterator_category     iterator_category;
        typedef typename T::pointer               pointer;
        typedef typename T::reference             reference;
    };

	// TOFIX
    template <class T>
    struct iterator_traits<T*>
	{
        typedef T                          value_type;
        typedef ptrdiff_t                  difference_type;
        // typedef random_access_iterator_tag iterator_category;
        typedef T*                         pointer;
        typedef T&                         reference;
    };
	// template< class T >
	// struct iterator_traits<const T*>;

	// template< class Iter >
	// class reverse_iterator;

	// template< bool B, class T = void >
	// struct enable_if;

	// template< class T >
	// struct is_integral;

	// // equal and/or lexicographical_compare

	// template<class T1, class T2>
	// struct pair;

	// template< class T1, class T2 >
	// std::pair<T1, T2> make_pair( T1 t, T2 u );
}

#endif