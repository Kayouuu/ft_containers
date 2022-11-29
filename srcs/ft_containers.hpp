/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_containers.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 10:17:30 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/29 10:49:42 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

// #include "stack.hpp"
// #include "vector.hpp"
// #include "iterators.hpp"
// #include "is_integral.hpp"
// #include "comparison.hpp"
// #include "pair.hpp"

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

#endif
