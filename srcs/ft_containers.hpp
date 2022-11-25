/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:17:30 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/24 17:56:22 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

// #include "stack/stack.hpp"
// #include "vector.hpp"
// #include "iterators.hpp"
#include "is_integral.hpp"
#include "comparison.hpp"

const class nullptr_t
{
public:
   template<class T>
   operator T*() const { return 0; }

   template<class C, class T>
    operator T C::*() const { return 0; }   

private:
   void operator&() const;

} ft_nullptr = {};

namespace	ft
{
	template <class T>
	struct iterator_traits;
	template <class T>
	struct iterator_traits<T*>;
	template< class T >
	struct iterator_traits<const T*>;

	// template<class T, class Allocator>
	// class vector;

	template<class T, class Container>
	class stack;

	template<bool B, class T = void>
	struct enable_if { };

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	// 	TODO
	// template<class T1, class T2>
	// struct pair;

	//	TODO
	// template< class T1, class T2 >
	// std::pair<T1, T2> make_pair( T1 t, T2 u );

	// template<class It>
	// typename std::iterator_traits<It>::difference_type do_distance(It first, It last, std::input_iterator_tag)
	// {
	// 	typename std::iterator_traits<It>::difference_type result = 0;
	// 	while (first != last) {
	// 		++first;
	// 		++result;
	// 	}
	// 	return result;
	// }

	// template<class It>
	// typename ft::iterator_traits<It>::difference_type	do_distance(It first, It last, std::random_access_iterator_tag)
	// {
	// 	return (last - first);
	// }

	// template< class It >
	// typename ft::iterator_traits<It>::difference_type	distance( It first, It last )
	// {
    // 	return (do_distance(first, last, typename std::iterator_traits<It>::iterator_category()));		
	// }
}

#endif
