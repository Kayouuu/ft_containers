/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:44:24 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/03 13:34:35 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector/vector.hpp"
#include "ft_containers.hpp"

int main()
{
	//expected output: 4
	ft::vector<int>	c;
	ft::vector<int>	b;
	c.push_back(1);
	c.push_back(2);
	c.push_back(3);
	
	b.push_back(4);
	b.push_back(5);
	b.push_back(6);

	// ft::vector<int>::iterator	it = c.begin();
	c.swap(b);
	std::cout << c.size() << " " << c.capacity() << std::endl;
	// std::cout << *c.end() << std::endl;
	std::cout << (c == b) << std::endl;
}
