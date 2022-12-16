/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:52:41 by psaulnie          #+#    #+#             */
/*   Updated: 2022/12/16 11:02:00 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <iomanip>

#include "map.hpp"

#include <fstream>
#include <ostream>
#include <algorithm>

void	write_result(std::string test, bool result, std::ofstream &std_output, std::ofstream &ft_output, bool last_test = true)
{
	std_output.close();
	ft_output.close();

	if (result)
		std::cout << "\033[0;37m" << test << std::setw(10) << " [\033[1;32m✓\033[0;37m]" << std::endl;
	else
	{
		std::cout << "\033[0;37m" << test << std::setw(10) << " [\033[1;31m✗\033[0;37m]" << std::endl;
		exit(0);
	}
	if (!last_test)
	{
		std_output.open("std_output.log");
		ft_output.open("ft_output.log");
	}
}

bool diff()
{
	std::ifstream	std_output("std_output.log", std::ifstream::binary|std::ifstream::ate);
	std::ifstream	ft_output("ft_output.log", std::ifstream::binary|std::ifstream::ate);
	
	if (std_output.tellg() != ft_output.tellg())
		return (false);
	std_output.seekg(0, std::ifstream::beg);
	ft_output.seekg(0, std::ifstream::beg);
	if	(std::equal(std::istreambuf_iterator<char>(std_output.rdbuf()),
						std::istreambuf_iterator<char>(),
						std::istreambuf_iterator<char>(ft_output.rdbuf())))
		return (true);
	return (false);
		
}

bool	insert1_test(std::ofstream &std_output, std::ofstream &ft_output)
{
	std::map<std::string, int>	m1;
	ft::map<std::string, int>	m2;

	m1.insert(std::pair<std::string, int>("salut", 2));
	m2.insert(ft::pair<std::string, int>("salut", 2));

	m1.insert(std::pair<std::string, int>("a", 2));
	m2.insert(ft::pair<std::string, int>("a", 2));

	std::pair<std::map<std::string, int>::iterator, bool> it1 = m1.insert(std::pair<std::string, int>("dfsg", 89));
	ft::pair<ft::map<std::string, int>::iterator, bool>  it2 = m2.insert(ft::pair<std::string, int>("dfsg", 89));

	std_output << (*it1.first).first << " | " << it1.second << std::endl;
	ft_output << (*it2.first).first << " | " << it2.second << std::endl;

	std_output << "Content is :" << std::endl;
	for (; m1.begin() != m1.end(); )
	{
		std_output << "- " << (m1.begin()->first) << " / " << (m1.begin()->second) << std::endl;
		std_output << "size: " << m1.size() << std::endl;
		m1.erase(m1.begin()->first);
	}
	ft_output << "Content is :" << std::endl;
	for (; m2.begin() != m2.end(); )
	{
		ft_output << "- " << (m2.begin()->first) << " / " << (m2.begin()->second) << std::endl;
		ft_output << "size: " << m2.size() << std::endl;
		m2.erase(m2.begin()->first);
	}

	return (diff());
}


int	main()
{
	std::ofstream	std_input;
	std::ofstream	ft_input;

	std_input.open("std_output.log");
	ft_input.open("ft_output.log");
	
	std::cout << "______  ___                    ________           _____             " << std::endl;
	std::cout << "___   |/  /_____ ________      ___  __/_____________  /_____________" << std::endl;
	std::cout << "__  /|_/ /_  __ `/__ __ \\     __  /  _  _ \\_  ___/  __/  _ \\_  ___/" << std::endl;
	std::cout << "_  /  / / / /_/ /__ /_/ /     _  /   /  __/(__  )/ /_ /  __/  /    " << std::endl;
	std::cout << "/_/  /_/  \\__,_/ _.____/      /_/    \\___//____/ \\__/ \\___//_/     " << std::endl;
    std::cout << "              /_/                                              		" << std::endl;

	/* --------------------TESTS-------------------- */

	// Insert One
	write_result("Insert one", insert1_test(std_input, ft_input), std_input, ft_input);

	/* ---------------------------------------------- */

	remove("ft_output.log");
	remove("std_output.log");
}