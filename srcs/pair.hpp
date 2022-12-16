/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:00:05 by psaulnie          #+#    #+#             */
/*   Updated: 2022/12/16 11:00:45 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

#include "ft_containers.hpp"

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef T1	first_type;
		typedef	T2	second_type;

		T1	first;
		T2	second;

		pair() : first(T1()), second(T2()) { }
		
		template<class U1, class U2>
		pair(pair<U1, U2> const &other) : first(other.first), second(other.second)// TOCHECK use templated pair for other
		{ }
		
		pair(first_type const &first, second_type const &second) : first(first), second(second) { }
	
		pair const	&operator=(const pair &other)
		{
			if (this == &other)
				return (*this);
			this->first = other.first;
			this->second = other.second;
			return (*this);
		}
	};

	template <class T1, class T2>
	ft::pair<T1, T2>	make_pair(T1 t, T2 u) { return (pair<T1, T2>(t, u)); }

	// TODO const & non-const
	template <class T1, class T2>
	bool	operator==(ft::pair<T1, T2> const &lhs, ft::pair<T1, T2> const &rhs) { return (lhs.first == rhs.first && lhs.second == rhs.second); }

	template <class T1, class T2>
	bool	operator!=(ft::pair<T1, T2> const &lhs, ft::pair<T1, T2> const &rhs) { return (lhs.first != rhs.first && lhs.second != rhs.second); }

	template <class T1, class T2>
	bool	operator<(ft::pair<T1, T2> const &lhs, ft::pair<T1, T2> const &rhs) { return (lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second)); }

	template <class T1, class T2>
	bool	operator<=(ft::pair<T1, T2> const &lhs, ft::pair<T1, T2> const &rhs) { return (!(rhs < lhs)); }

	template <class T1, class T2>
	bool	operator>(ft::pair<T1, T2> const &lhs, ft::pair<T1, T2> const &rhs) { return (rhs < lhs); }

	template <class T1, class T2>
	bool	operator>=(ft::pair<T1, T2> const &lhs, ft::pair<T1, T2> const &rhs) { return (!(lhs < rhs)); }
}

#endif