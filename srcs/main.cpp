/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:44:24 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/14 11:41:26 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "is_integral.hpp"
#include "vector.hpp"
#include "ft_containers.hpp"

int		main(void)
{
	{
		std::vector<int>	v;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		std::cout << v.size() << " " << v.capacity() << std::endl;
		std::vector<int>::iterator		vb = v.begin();
		std::vector<int>::iterator		va = v.begin() + 2;
		std::vector<int>::iterator		ve = v.end();
		if ((vb - va) == -1)
			(void)v;
		// ft::vector<int>::const_iterator	ve = v.end();
		// std::cout << *(v.insert(va, vb, ve)) << std::endl;
		for (int i = 0; i < 5; i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
		std::cout << *(v.erase(vb, va)) << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
		std::cout << (vb >= ve) << std::endl;
		std::cout << v.size() << " " << v.capacity() << std::endl;
	}
	std::cout << "----------------------" << std::endl;
	{
		ft::vector<int>	v;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		std::cout << v.size() << " " << v.capacity() << std::endl;
		ft::vector<int>::iterator		vb = v.begin();
		ft::vector<int>::iterator		va = v.begin() + 2;
		ft::vector<int>::iterator		ve = v.end();
		if ((vb - va) == -1)
			(void)v;
		// std::cout << *(v.insert(va, vb, ve)) << std::endl;
		for (int i = 0; i < 5; i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
		std::cout << *(v.erase(vb, va)) << std::endl;
		for (int i = 0; i < 3; i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
		std::cout << (vb >= ve) << std::endl;
		std::cout << v.size() << " " << v.capacity() << std::endl;
	}
}