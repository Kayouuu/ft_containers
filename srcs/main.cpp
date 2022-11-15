/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:44:24 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/15 16:46:06 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "is_integral.hpp"
#include "vector.hpp"
#include "ft_containers.hpp"

int		main(void)
{
    std::vector<int> v;
    ft::vector<int> tmp, tmp2, vector;
    vector.assign(3, 3);
    tmp.assign(4000 * 10000, 1);
    tmp2.assign(4 * 10000, 1);
    vector.assign(tmp.begin(), tmp.end());
    v.push_back(vector[1]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
    vector.assign(tmp2.begin(), tmp2.end());
    v.push_back(vector[444]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());
	for 
}