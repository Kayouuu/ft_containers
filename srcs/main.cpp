/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaulnie <psaulnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:44:24 by psaulnie          #+#    #+#             */
/*   Updated: 2022/11/17 15:45:31 by psaulnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "is_integral.hpp"
#include "vector.hpp"
#include "ft_containers.hpp"

struct TestStruct {
	int a;
	float b;
	std::string c;
	int *ptr;

	TestStruct(): a(0), b(0), c(""), ptr(new int(5)) {}
	TestStruct(const TestStruct& src) : ptr(new int(5)) { *this = src; }
	TestStruct(const int& A, const float& B, const std::string& C)
		: a(A), b(B), c(C), ptr(new int(5)) {}
	~TestStruct() { delete ptr; }

	TestStruct& operator=(const TestStruct& rhs) {
		if (this == &rhs) return *this;
		a = rhs.a;
		b = rhs.b;
		c = rhs.c;
		return *this;
	}
	TestStruct operator*(const int& n) const {
		TestStruct tmp = *this;
		tmp.a *= n;
		tmp.b *= n;
		tmp.c += tmp.c;
		return tmp;
	}
};

int main()
{
	ft::vector <int> v(10, 5);
	ft::vector<int> vector(5, v[0] * 2);
	vector.assign(v.begin() + v.size() / 4, v.end() - v.size() / 4);
	for (int i = 0; i < vector.size(); i++)
		std::cout << vector[i] << std::endl;
}