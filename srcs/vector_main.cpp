/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:44:24 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/18 17:14:21 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "is_integral.hpp"
#include "vector.hpp"
#include "ft_containers.hpp"

#include <fstream>
#include <ostream>
#include <algorithm>

void	write_result(std::string test, bool result, std::ofstream &std_input, std::ofstream &ft_input, bool last_test = true)
{
	std_input.close();
	ft_input.close();

	if (result)
		std::cout << "\033[0;37m" << test << " [\033[1;32m✓\033[0;37m]" << std::endl;
	else
	{
		std::cout << "\033[0;37m" << test << " [\033[1;31m✗\033[0;37m]" << std::endl;
		exit(0);
	}

	if (!last_test)
	{
		std_input.open("std_input.log");
		ft_input.open("ft_input.log");
	}
}

bool diff()
{
	std::ifstream	std_output("std_input.log", std::ifstream::binary|std::ifstream::ate);
	std::ifstream	ft_output("ft_input.log", std::ifstream::binary|std::ifstream::ate);
	
	if (std_output.tellg() != ft_output.tellg())
	{
		// std::cout << "Test failed !" << std::endl;
		return (false);
	}
	std_output.seekg(0, std::ifstream::beg);
	ft_output.seekg(0, std::ifstream::beg);
	if	(std::equal(std::istreambuf_iterator<char>(std_output.rdbuf()),
						std::istreambuf_iterator<char>(),
						std::istreambuf_iterator<char>(ft_output.rdbuf())))
	{
		return (true);
	}
	return (false);
		
}

bool	insert_test(std::ofstream &std_input, std::ofstream &ft_input)
{
	std::vector<int>	v1;
	ft::vector<int>		v2;

	std_input << *(v1.insert(v1.begin(), 2)) << std::endl;
	ft_input << *(v2.insert(v2.begin(), 2)) << std::endl;

	std_input << *(v1.insert(v1.begin(), -1)) << std::endl;
	ft_input << *(v2.insert(v2.begin(), -1)) << std::endl;

	std_input << *(v1.insert(v1.begin(), 42)) << std::endl;
	ft_input << *(v2.insert(v2.begin(), 42)) << std::endl;

	std_input << *(v1.insert(v1.begin(), 0)) << std::endl;
	ft_input << *(v2.insert(v2.begin(), 0)) << std::endl;

	std_input << *(v1.erase(v1.begin() + 3)) << std::endl;
	ft_input << *(v2.erase(v2.begin() + 3)) << std::endl;
	
	std_input << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_input << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	std_input << "Content is :" << std::endl;
	for (; v1.begin() != v1.end(); )
	{
		std_input << "- " << *(v1.end() - 1) << std::endl;
		v1.pop_back();
	}
	ft_input << "Content is :" << std::endl;
	for (; v2.begin() != v2.end(); )
	{
		ft_input << "- " << *(v2.end() - 1) << std::endl;
		v2.pop_back();
	}
	return (diff());
}


int	main()
{
	std::ofstream	std_input;
	std::ofstream	ft_input;

	std_input.open("std_input.log");
	ft_input.open("ft_input.log");
	
	std::cout << "___    __          _____                  ________           _____             " << std::endl;
	std::cout << "__ |  / /____________  /______________    ___  __/_____________  /_____________" << std::endl;
	std::cout << "__ | / /_  _ \\  ___/  __/  __ \\_  ___/    __  /  _  _ \\_  ___/  __/  _ \\_  ___/" << std::endl;
	std::cout << "__ |/ / /  __/ /__ / /_ / /_/ /  /        _  /   /  __/(__  )/ /_ /  __/  /    " << std::endl;
	std::cout << "_____/  \\___/\\___/ \\__/ \\____//_/         /_/    \\___//____/ \\__/ \\___//_/     " << std::endl << std::endl;
	/* --------------------TESTS-------------------- */

	// 	Insert
	write_result("Insert wth position", insert_test(std_input, ft_input), std_input, ft_input);

	/* ---------------------------------------------- */
}