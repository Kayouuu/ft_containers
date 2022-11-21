/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_main.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:44:24 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/21 14:56:37 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <iomanip>

#include "is_integral.hpp"
#include "vector.hpp"
#include "ft_containers.hpp"

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

bool	assign1_test(std::ofstream &std_output, std::ofstream &ft_output)
{
	std::vector<int>	v1;
	ft::vector<int>		v2;

	try
	{
		v1.assign(-1, 5);
	}
	catch(const std::exception& e)
	{
		std_output << e.what() << '\n';
	}
	
	try
	{
		v2.assign(-1, 5);
	}
	catch(const std::exception& e)
	{
		ft_output << e.what() << '\n';
	}

	v1.assign(5, 5);
	v2.assign(5, 5);
	
	std_output << "Content is :" << std::endl;
	for (; v1.begin() != v1.end(); )
	{
		std_output << "- " << *(v1.end() - 1) << std::endl;
		std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
		v1.pop_back();
	}
	ft_output << "Content is :" << std::endl;
	for (; v2.begin() != v2.end(); )
	{
		ft_output << "- " << *(v2.end() - 1) << std::endl;
		ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;
		v2.pop_back();
	}

	v1.assign(10, 10);
	v2.assign(10, 10);
	
	std_output << "Content is :" << std::endl;
	for (; v1.begin() != v1.end(); )
	{
		std_output << "- " << *(v1.end() - 1) << std::endl;
		std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
		v1.pop_back();
	}
	ft_output << "Content is :" << std::endl;
	for (; v2.begin() != v2.end(); )
	{
		ft_output << "- " << *(v2.end() - 1) << std::endl;
		ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;
		v2.pop_back();
	}

	v1.assign(5, 10);
	v2.assign(5, 10);

	std_output << "Content is :" << std::endl;
	for (; v1.begin() != v1.end(); )
	{
		std_output << "- " << *(v1.end() - 1) << std::endl;
		std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
		v1.pop_back();
	}
	ft_output << "Content is :" << std::endl;
	for (; v2.begin() != v2.end(); )
	{
		ft_output << "- " << *(v2.end() - 1) << std::endl;
		ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;
		v2.pop_back();
	}

	return (diff());
}

bool	assign2_test(std::ofstream &std_output, std::ofstream &ft_output)
{
	std::vector<int>	v1;
	ft::vector<int>		v2;
	std::vector<int>	v3;
	ft::vector<int>		v4;

	v3.assign(5, 5);
	v4.assign(5, 5);
	

	v1.assign(v3.begin(), v3.end());
	v2.assign(v4.begin(), v4.end());
	std_output << "Content is :" << std::endl;
	for (; v1.begin() != v1.end(); )
	{
		std_output << "- " << *(v1.end() - 1) << std::endl;
		std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
		v1.pop_back();
	}
	ft_output << "Content is :" << std::endl;
	for (; v2.begin() != v2.end(); )
	{
		ft_output << "- " << *(v2.end() - 1) << std::endl;
		ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;
		v2.pop_back();
	}
	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;
	try
	{
		v1.assign(v3.begin(), v3.begin());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		v2.assign(v4.begin(), v4.begin()); 
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std_output << "Content is :" << std::endl;
	for (; v1.begin() != v1.end(); )
	{
		std_output << "- " << *(v1.end() - 1) << std::endl;
		std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
		v1.pop_back();
	}
	ft_output << "Content is :" << std::endl;
	for (; v2.begin() != v2.end(); )
	{
		ft_output << "- " << *(v2.end() - 1) << std::endl;
		ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;
		v2.pop_back();
	}

	try
	{
		v1.assign(v3.rend(), v3.rbegin());
	}
	catch(const std::exception& e)
	{
		std_output << e.what() << '\n';
	}

	try
	{
		v2.assign(v4.rend(), v4.rbegin());
	}
	catch(const std::exception& e)
	{
		ft_output << e.what() << '\n';
	}
	

	std_output << "Content is :" << std::endl;
	for (; v1.begin() != v1.end(); )
	{
		std_output << "- " << *(v1.end() - 1) << std::endl;
		std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
		v1.pop_back();
	}
	ft_output << "Content is :" << std::endl;
	for (; v2.begin() != v2.end(); )
	{
		ft_output << "- " << *(v2.end() - 1) << std::endl;
		ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;
		v2.pop_back();
	}
	return (diff());
}

bool	at_test(std::ofstream &std_output, std::ofstream &ft_output)
{
	std::vector<int>	v1;
	ft::vector<int>		v2;

	v1.push_back(1);
	v2.push_back(1);
	v1.push_back(2);
	v2.push_back(2);
	v1.push_back(3);
	v2.push_back(3);
	v1.push_back(4);
	v2.push_back(4);
	v1.push_back(5);
	v2.push_back(5);
	v1.push_back(6);
	v2.push_back(6);


	std_output << v1.at(3) << std::endl;
	ft_output << v2.at(3) << std::endl;

	v1.resize(10);
	v2.resize(10);

	std_output << v1.at(3) << std::endl;
	ft_output << v2.at(3) << std::endl;

	std_output << "Content is :" << std::endl;
	for (; v1.begin() != v1.end(); )
	{
		std_output << "- " << *(v1.end() - 1) << std::endl;
		std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
		v1.pop_back();
	}
	ft_output << "Content is :" << std::endl;
	for (; v2.begin() != v2.end(); )
	{
		ft_output << "- " << *(v2.end() - 1) << std::endl;
		ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;
		v2.pop_back();
	}

	return (diff());
}

bool	capacity_test(std::ofstream &std_output, std::ofstream &ft_output)
{
	std::vector<int>	v1;
	ft::vector<int>		v2;
	
	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << " ; empty: " << v1.empty() << " ; max_size: " << v1.max_size() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << " ; empty: " << v1.empty() << " ; max_size: " << v1.max_size() << std::endl;

	v1.reserve(1);
	v2.reserve(1);

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << " ; empty: " << v1.empty() << " ; max_size: " << v1.max_size() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << " ; empty: " << v1.empty() << " ; max_size: " << v1.max_size() << std::endl;

	v1.reserve(1);
	v2.reserve(1);
	
	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << " ; empty: " << v1.empty() << " ; max_size: " << v1.max_size() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << " ; empty: " << v1.empty() << " ; max_size: " << v1.max_size() << std::endl;

	v1.reserve(50);
	v2.reserve(50);

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << " ; empty: " << v1.empty() << " ; max_size: " << v1.max_size() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << " ; empty: " << v1.empty() << " ; max_size: " << v1.max_size() << std::endl;
	
	v1.assign(50, 1);
	v2.assign(50, 1);

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << " ; empty: " << v1.empty() << " ; max_size: " << v1.max_size() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << " ; empty: " << v1.empty() << " ; max_size: " << v1.max_size() << std::endl;

	v1.resize(1);
	v2.resize(1);

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << " ; empty: " << v1.empty() << " ; max_size: " << v1.max_size() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << " ; empty: " << v1.empty() << " ; max_size: " << v1.max_size() << std::endl;

	return (diff());
}

bool	insert1_test(std::ofstream &std_output, std::ofstream &ft_output)
{
	std::vector<int>	v1;
	ft::vector<int>		v2;

	std_output << *(v1.insert(v1.begin(), 2)) << std::endl;
	ft_output << *(v2.insert(v2.begin(), 2)) << std::endl;

	std_output << *(v1.insert(v1.begin(), -1)) << std::endl;
	ft_output << *(v2.insert(v2.begin(), -1)) << std::endl;

	std_output << *(v1.insert(v1.begin(), 42)) << std::endl;
	ft_output << *(v2.insert(v2.begin(), 42)) << std::endl;

	std_output << *(v1.insert(v1.begin(), 0)) << std::endl;
	ft_output << *(v2.insert(v2.begin(), 0)) << std::endl;

	std_output << *(v1.erase(v1.begin() + 2)) << std::endl;
	ft_output << *(v2.erase(v2.begin() + 2)) << std::endl;
	
	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	std_output << "Content is :" << std::endl;
	for (; v1.begin() != v1.end(); )
	{
		std_output << "- " << *(v1.end() - 1) << std::endl;
		v1.pop_back();
	}
	ft_output << "Content is :" << std::endl;
	for (; v2.begin() != v2.end(); )
	{
		ft_output << "- " << *(v2.end() - 1) << std::endl;
		v2.pop_back();
	}
	return (diff());
}

bool	insert2_test(std::ofstream &std_output, std::ofstream &ft_output)
{
	std::vector<int>	v1;
	ft::vector<int>		v2;

	std_output << *(v1.insert(v1.begin(), 5, 2)) << std::endl;
	ft_output << *(v2.insert(v2.begin(), 5, 2)) << std::endl;

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	std_output << *(v1.insert(v1.begin(), 1, -1)) << std::endl;
	ft_output << *(v2.insert(v2.begin(), -1)) << std::endl;

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	std_output << *(v1.insert(v1.begin(), 1, 42)) << std::endl;
	ft_output << *(v2.insert(v2.begin(), 42)) << std::endl;
	
	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	std_output << "Content is :" << std::endl;
	for (; v1.begin() != v1.end(); )
	{
		std_output << "- " << *(v1.end() - 1) << std::endl;
		v1.pop_back();
	}
	ft_output << "Content is :" << std::endl;
	for (; v2.begin() != v2.end(); )
	{
		ft_output << "- " << *(v2.end() - 1) << std::endl;
		v2.pop_back();
	}
	return (diff());
}

bool	insert3_test(std::ofstream &std_output, std::ofstream &ft_output)
{
	std::vector<int>	v1;
	ft::vector<int>		v2;

	std_output << *(v1.insert(v1.begin(), 5, 2)) << std::endl;
	ft_output << *(v2.insert(v2.begin(), 5, 2)) << std::endl;

	std_output << *(v1.insert(v1.begin() + 2, v1.begin(), v1.end())) << std::endl;
	ft_output << *(v2.insert(v2.begin() + 2, v2.begin(), v2.end())) << std::endl;

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	std_output << *(v1.insert(v1.begin(), v1.begin() + 1, v1.end())) << std::endl;
	ft_output << *(v2.insert(v2.begin(), v2.begin() + 1, v2.end())) << std::endl;
	
	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	std_output << "Content is :" << std::endl;
	for (; v1.begin() != v1.end(); )
	{
		std_output << "- " << *(v1.end() - 1) << std::endl;
		v1.pop_back();
	}
	ft_output << "Content is :" << std::endl;
	for (; v2.begin() != v2.end(); )
	{
		ft_output << "- " << *(v2.end() - 1) << std::endl;
		v2.pop_back();
	}
	return (diff());
}

bool	clear_test(std::ofstream &std_output, std::ofstream &ft_output)
{
	std::vector<int>	v1;
	ft::vector<int>		v2;

	v1.push_back(1);
	v2.push_back(1);
	v1.push_back(2);
	v2.push_back(2);
	v1.push_back(3);
	v2.push_back(3);
	v1.push_back(4);
	v2.push_back(4);
	v1.push_back(5);
	v2.push_back(5);
	v1.push_back(6);
	v2.push_back(6);

	v1.clear();
	v2.clear();

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;
	
	v1.clear();
	v2.clear();

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;
	
	std_output << "Content is :" << std::endl;
	for (; v1.begin() != v1.end(); )
	{
		std_output << "- " << *(v1.end() - 1) << std::endl;
		v1.pop_back();
	}
	ft_output << "Content is :" << std::endl;
	for (; v2.begin() != v2.end(); )
	{
		ft_output << "- " << *(v2.end() - 1) << std::endl;
		v2.pop_back();
	}

	std::vector<int*>	a;
	std::vector<int*>	b;

	return (diff());
}

bool	push_back_test(std::ofstream &std_output, std::ofstream &ft_output)
{
	std::vector<int>	v1;
	ft::vector<int>		v2;

	v1.push_back(1);
	v2.push_back(1);
	v1.push_back(2);
	v2.push_back(2);
	v1.push_back(3);
	v2.push_back(3);
	v1.push_back(4);
	v2.push_back(4);
	v1.push_back(5);
	v2.push_back(5);
	v1.push_back(6);
	v2.push_back(6);

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	std_output << "Content is :" << std::endl;
	for (; v1.begin() != v1.end(); )
	{
		std_output << "- " << *(v1.end() - 1) << std::endl;
		v1.pop_back();
	}
	ft_output << "Content is :" << std::endl;
	for (; v2.begin() != v2.end(); )
	{
		ft_output << "- " << *(v2.end() - 1) << std::endl;
		v2.pop_back();
	}

	v1.clear();
	v2.clear();

	v1.reserve(5);

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	v1.push_back(1);
	v2.push_back(1);
	v1.push_back(2);
	v2.push_back(2);
	v1.push_back(3);
	v2.push_back(3);
	v1.push_back(4);
	v2.push_back(4);
	v1.push_back(5);
	v2.push_back(5);
	v1.push_back(6);
	v2.push_back(6);

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	std_output << "Content is :" << std::endl;
	for (; v1.begin() != v1.end(); )
	{
		std_output << "- " << *(v1.end() - 1) << std::endl;
		v1.pop_back();
	}
	ft_output << "Content is :" << std::endl;
	for (; v2.begin() != v2.end(); )
	{
		ft_output << "- " << *(v2.end() - 1) << std::endl;
		v2.pop_back();
	}

	return (diff());
}

bool	pop_back_test(std::ofstream &std_output, std::ofstream &ft_output)
{
	std::vector<int>	v1;
	ft::vector<int>		v2;

	v1.push_back(1);
	v2.push_back(1);
	v1.push_back(2);
	v2.push_back(2);
	v1.push_back(3);
	v2.push_back(3);
	v1.push_back(4);
	v2.push_back(4);
	v1.push_back(5);
	v2.push_back(5);
	v1.push_back(6);
	v2.push_back(6);

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	std_output << "Content is :" << std::endl;
	for (; v1.begin() != v1.end(); )
	{
		std_output << "- " << *(v1.end() - 1) << std::endl;
		std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
		v1.pop_back();
	}
	ft_output << "Content is :" << std::endl;
	for (; v2.begin() != v2.end(); )
	{
		ft_output << "- " << *(v2.end() - 1) << std::endl;
		ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;
		v2.pop_back();
	}	
	return (diff());
}

bool	erase1_test(std::ofstream &std_output, std::ofstream &ft_output)
{
    std::vector<int>    v1;
    ft::vector<int>     v2;

    std_output << *(v1.insert(v1.begin(), 5, 2)) << std::endl;
    ft_output << *(v2.insert(v2.begin(), 5, 2)) << std::endl;

    std_output << *(v1.insert(v1.begin() + 2, v1.begin(), v1.end())) << std::endl;
    ft_output << *(v2.insert(v2.begin() + 2, v2.begin(), v2.end())) << std::endl;

    std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
    ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

    std_output << *(v1.insert(v1.begin(), v1.begin() + 1, v1.end())) << std::endl;
    ft_output << *(v2.insert(v2.begin(), v2.begin() + 1, v2.end())) << std::endl;
    
    std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
    ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

    std_output << *(v1.erase(v1.begin() + 2)) << std::endl;
    ft_output << *(v2.erase(v2.begin() + 2)) << std::endl;

    std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
    ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

    std_output << *(v1.erase(v1.begin() + 3)) << std::endl;
    ft_output << *(v2.erase(v2.begin() + 3)) << std::endl;

    std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
    ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

    std_output << "Content is :" << std::endl;
    for (; v1.begin() != v1.end(); )
    {
        std_output << "- " << *(v1.end() - 1) << std::endl;
        v1.pop_back();
    }
    ft_output << "Content is :" << std::endl;
    for (; v2.begin() != v2.end(); )
    {
        ft_output << "- " << *(v2.end() - 1) << std::endl;
        v2.pop_back();
    }
    return (diff());    
}

bool	erase2_test(std::ofstream &std_output, std::ofstream &ft_output)
{
	std::vector<int>	v1;
	ft::vector<int>		v2;

	std_output << *(v1.insert(v1.begin(), 5, 2)) << std::endl;
	ft_output << *(v2.insert(v2.begin(), 5, 2)) << std::endl;

	std_output << *(v1.insert(v1.begin() + 2, v1.begin(), v1.end())) << std::endl;
	ft_output << *(v2.insert(v2.begin() + 2, v2.begin(), v2.end())) << std::endl;

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	std_output << *(v1.insert(v1.begin(), v1.begin() + 1, v1.end())) << std::endl;
	ft_output << *(v2.insert(v2.begin(), v2.begin() + 1, v2.end())) << std::endl;
	
	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	std_output << *(v1.erase(v1.begin() + 2)) << std::endl;
	ft_output << *(v2.erase(v2.begin() + 2)) << std::endl;

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	v1.erase(v1.begin(), v1.end());
	v2.erase(v2.begin(), v2.end());

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	std_output << "Content is :" << std::endl;
	for (; v1.begin() != v1.end(); )
	{
		std_output << "- " << *(v1.end() - 1) << std::endl;
		v1.pop_back();
	}
	ft_output << "Content is :" << std::endl;
	for (; v2.begin() != v2.end(); )
	{
		ft_output << "- " << *(v2.end() - 1) << std::endl;
		v2.pop_back();
	}

	std_output << *(v1.insert(v1.begin(), 5, 2)) << std::endl;
	ft_output << *(v2.insert(v2.begin(), 5, 2)) << std::endl;

	std_output << *(v1.insert(v1.begin() + 2, v1.begin(), v1.end())) << std::endl;
	ft_output << *(v2.insert(v2.begin() + 2, v2.begin(), v2.end())) << std::endl;

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	std_output << *(v1.insert(v1.begin(), v1.begin() + 1, v1.end())) << std::endl;
	ft_output << *(v2.insert(v2.begin(), v2.begin() + 1, v2.end())) << std::endl;
	
	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	std_output << *(v1.erase(v1.begin() + 2)) << std::endl;
	ft_output << *(v2.erase(v2.begin() + 2)) << std::endl;

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	std_output << *(v1.erase(v1.begin(), v1.begin() + 2)) << std::endl;
	ft_output << *(v2.erase(v2.begin(), v2.begin() + 2)) << std::endl;
	
	return (diff());
}

bool	resize_test(std::ofstream &std_output, std::ofstream &ft_output)
{
	std::vector<int>	v1;
	ft::vector<int>		v2;

	v1.resize(10);
	v2.resize(10);

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	v1.clear();
	v2.clear();

	v1.push_back(1);
	v2.push_back(1);
	v1.push_back(2);
	v2.push_back(2);
	v1.push_back(3);
	v2.push_back(3);
	v1.push_back(4);
	v2.push_back(4);
	v1.push_back(5);
	v2.push_back(5);
	v1.push_back(6);
	v2.push_back(6);

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	v1.resize(100);
	v2.resize(100);

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	std_output << "Content is :" << std::endl;
	for (; v1.begin() != v1.end(); )
	{
		std_output << "- " << *(v1.end() - 1) << std::endl;
		std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
		v1.pop_back();
	}
	ft_output << "Content is :" << std::endl;
	for (; v2.begin() != v2.end(); )
	{
		ft_output << "- " << *(v2.end() - 1) << std::endl;
		ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;
		v2.pop_back();
	}

	v1.resize(5);
	v2.resize(5);

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	std_output << "Content is :" << std::endl;
	for (; v1.begin() != v1.end(); )
	{
		std_output << "- " << *(v1.end() - 1) << std::endl;
		std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
		v1.pop_back();
	}
	ft_output << "Content is :" << std::endl;
	for (; v2.begin() != v2.end(); )
	{
		ft_output << "- " << *(v2.end() - 1) << std::endl;
		ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;
		v2.pop_back();
	}

	return (diff());
}

bool	swap_test(std::ofstream &std_output, std::ofstream &ft_output)
{
	std::vector<int>	v1;
	ft::vector<int>		v2;
	std::vector<int>	v3;
	ft::vector<int>		v4;

	v1.push_back(0);
	v2.push_back(0);
	v1.push_back(10);
	v2.push_back(10);
	v1.push_back(11);
	v2.push_back(11);
	v1.push_back(13);
	v2.push_back(13);
	v1.push_back(14);
	v2.push_back(14);
	v1.push_back(15);
	v2.push_back(15);

	v3.push_back(1);
	v4.push_back(1);
	v3.push_back(2);
	v4.push_back(2);
	v3.push_back(3);
	v4.push_back(3);
	v3.push_back(4);
	v4.push_back(4);
	v3.push_back(5);
	v4.push_back(5);
	v3.push_back(6);
	v4.push_back(6);

	std::vector<int>::iterator std_it = v1.begin() + 2;
	ft::vector<int>::iterator ft_it = v2.begin() + 2;

	std_output << *std_it << std::endl;
	ft_output << *ft_it << std::endl;
	
	std::swap(v1, v3);
	ft::swap(v2, v4);

	std_output << *std_it << std::endl;
	ft_output << *ft_it << std::endl;

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	std::swap(v1, v3);
	ft::swap(v2, v4);

	std_output << *std_it << std::endl;
	ft_output << *ft_it << std::endl;

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	return (diff());
}

bool	reserve_test(std::ofstream &std_output, std::ofstream &ft_output)
{
	std::vector<int>	v1;
	ft::vector<int>		v2;
	
	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	v1.push_back(0);
	v2.push_back(0);
	v1.push_back(10);
	v2.push_back(10);
	v1.push_back(11);
	v2.push_back(11);
	v1.push_back(13);
	v2.push_back(13);
	v1.push_back(14);
	v2.push_back(14);
	v1.push_back(15);
	v2.push_back(15);

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	v1.clear();
	v2.clear();

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	v1.reserve(20);
	v2.reserve(20);

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	v1.push_back(0);
	v2.push_back(0);
	v1.push_back(10);
	v2.push_back(10);
	v1.push_back(11);
	v2.push_back(11);
	v1.push_back(13);
	v2.push_back(13);
	v1.push_back(14);
	v2.push_back(14);
	v1.push_back(15);
	v2.push_back(15);

	v1.reserve(5);
	v2.reserve(5);

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	v1.reserve(100);
	v2.reserve(100);

	std_output << "size: " << v1.size() << " ; capacity: " << v1.capacity() << std::endl;
	ft_output << "size: " << v2.size() << " ; capacity: " << v2.capacity() << std::endl;

	return (diff());
}

int	main()
{
	std::ofstream	std_input;
	std::ofstream	ft_input;

	std_input.open("std_output.log");
	ft_input.open("ft_output.log");
	
	std::cout << "___    __          _____                  ________           _____             " << std::endl;
	std::cout << "__ |  / /____________  /______________    ___  __/_____________  /_____________" << std::endl;
	std::cout << "__ | / /_  _ \\  ___/  __/  __ \\_  ___/    __  /  _  _ \\_  ___/  __/  _ \\_  ___/" << std::endl;
	std::cout << "__ |/ / /  __/ /__ / /_ / /_/ /  /        _  /   /  __/(__  )/ /_ /  __/  /    " << std::endl;
	std::cout << "_____/  \\___/\\___/ \\__/ \\____//_/         /_/    \\___//____/ \\__/ \\___//_/     " << std::endl << std::endl;
	/* --------------------TESTS-------------------- */

	// Assign
	write_result("Assign", assign1_test(std_input, ft_input), std_input, ft_input);
	// Assign Iterator
	write_result("Assign iterator", assign2_test(std_input, ft_input), std_input, ft_input);
	// At
	write_result("At", at_test(std_input, ft_input), std_input, ft_input);
	// Empty / Size / Max_Size / Capacity
	write_result("Empty / Size / Max_Size / Capacity", capacity_test(std_input, ft_input), std_input, ft_input);
	// Reserve
	write_result("Reserve", reserve_test(std_input, ft_input), std_input, ft_input);
	// Resize
	write_result("Resize", resize_test(std_input, ft_input), std_input, ft_input);
	// Clear
	write_result("Clear", clear_test(std_input, ft_input), std_input, ft_input);
	// 	Insert with position
	write_result("Insert with position", insert1_test(std_input, ft_input), std_input, ft_input);
	// Insert multiple with position
	write_result("Insert multiple with position", insert2_test(std_input, ft_input), std_input, ft_input);
	// Insert range
	write_result("Insert range", insert3_test(std_input, ft_input), std_input, ft_input);
	// Erase 1
	write_result("Erase", erase1_test(std_input, ft_input), std_input, ft_input);
	// Erase 2
	write_result("Erase range", erase2_test(std_input, ft_input), std_input, ft_input);
	// Push_back
	write_result("Push_back", push_back_test(std_input, ft_input), std_input, ft_input);
	// Pop_back
	write_result("Pop_back", pop_back_test(std_input, ft_input), std_input, ft_input);
	// Swap 
	write_result("Swap", swap_test(std_input, ft_input), std_input, ft_input);
	/* ---------------------------------------------- */

	remove("ft_output.log");
	remove("std_output.log");
}