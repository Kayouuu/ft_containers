/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:44:24 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/02 12:12:53 by psaulnie         ###   ########.fr       */
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
		for (int i = 0; i < 20; i++)
		{
			vector.push_back('a');
		}
		std::cout << "------------------" << std::endl;
		for (int i = 0; i < 20; i++)
			std::cout << "[" << vector[i] << "] " << i << std::endl;
		std::cout << vector.size() << " " << vector.capacity() << std::endl;
	}
	{
		std::cout << "--------MINE-------" << std::endl;
		ft::vector<char>	vector;

		for (int i = 0; i < 20; i++)
		{
			vector.push_back('a');
		}
		std::cout << "------------------" << std::endl;
		for (int i = 0; i < 20; i++)
			std::cout << "[" << vector[i] << "] " << i << std::endl;
		std::cout << vector.size() << " " << vector.capacity() << std::endl;
	}
}
