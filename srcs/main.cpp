/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:44:24 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/02 16:23:15 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector/vector.hpp"
#include "ft_containers.hpp"

int main()
{
	{
		std::vector<char>	vector;
		std::vector<char>::iterator	it;

		for (int i = 0; i < 20; i++)
		{
			vector.push_back('a');
		}
		vector.pop_back();
		it = vector.end();
		std::cout << "------------------" << std::endl;
		for (int i = 0; i < 19; i++)
			std::cout << "[" << vector[i] << "] " << i << std::endl;
		*it;
		std::cout << *it << std::endl;
	}
	{
		std::cout << "--------MINE-------" << std::endl;
		ft::vector<char>	vector;
		ft::vector<char>::iterator	it;

		for (int i = 0; i < 20; i++)
		{
			vector.push_back('a');
		}
		vector.pop_back();
		it = vector.end();
		std::cout << "------------------" << std::endl;
		for (int i = 0; i < 19; i++)
			std::cout << "[" << vector[i] << "] " << i << std::endl;
		*it;
		std::cout << *it << std::endl;
	}
}
