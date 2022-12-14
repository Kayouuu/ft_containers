/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:49:30 by psaulnie          #+#    #+#             */
/*   Updated: 2022/12/12 11:10:41 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

#include <type_traits>

namespace	ft
{
	template<bool B, class T = void>
	struct enable_if { };

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template <typename T>
	struct is_integral : std::false_type {};

	template <>
	struct is_integral<bool> : std::true_type {};
	template <>
	struct is_integral<char> : std::true_type {};
	template <>
	struct is_integral<char16_t> : std::true_type {};
	template <>
	struct is_integral<char32_t> : std::true_type {};
	template <>
	struct is_integral<wchar_t> : std::true_type {};
	template <>
	struct is_integral<signed char> : std::true_type {};
	template <>
	struct is_integral<short int> : std::true_type {};
	template <>
	struct is_integral<int> : std::true_type {};
	template <>
	struct is_integral<long int> : std::true_type {};
	// template <>
	// struct is_integral<long long int> : std::true_type {};
	template <>
	struct is_integral<unsigned char> : std::true_type {};
	template <>
	struct is_integral<unsigned short int> : std::true_type {};
	template <>
	struct is_integral<unsigned int> : std::true_type {};
	template <>
	struct is_integral<unsigned long int> : std::true_type {};
	// template <>
	// struct is_integral<unsigned long long int> : std::true_type {};

	template<class A, class B>
	struct	is_same : std::false_type { };

	template<class T>
	struct	is_same<T, T> : std::true_type { };
	
}

#endif
