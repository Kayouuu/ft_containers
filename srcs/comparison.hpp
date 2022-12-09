/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:38:09 by psaulnie          #+#    #+#             */
/*   Updated: 2022/12/09 09:58:34 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

#include "is_integral.hpp"

namespace ft
{
	template<bool B, class T>
	struct enable_if;

	template<class T>
	struct enable_if<true, T>;
	
	template< class InputIt1, class InputIt2 >
	bool equal( InputIt1 first1, InputIt1 last1, typename ft::enable_if< !ft::is_integral< InputIt2 >::value, InputIt2>::type first2 )
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!(*first1 == *first2)) {
				return (false);
			}
		}
		return (true);	
	}

	template< class InputIt1, class InputIt2, class BinaryPredicate >
	bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p )
	{
		for (; first1 != last1; ++first1, ++first2) {
			if (!p(*first1, *first2)) {
				return (false);
			}
		}
		return (true);
	}

	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, typename ft::enable_if< !ft::is_integral< InputIt2 >::value, InputIt2>::type last2)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (comp(*first1, *first2))
				return (true);
			if (comp(*first2, *first1))
				return (false);
		}
		return (first1 == last1) && (first2 != last2);
	}
}

#endif
