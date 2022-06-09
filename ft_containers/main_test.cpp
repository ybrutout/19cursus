#include <iostream>
#include <vector>
#include "vector.hpp"
#include <iterator>

int		main(void)
{
	std::vector<int>		real;
	std::vector<int>		e_r;
	std::vector<int>		tp;
	ft::vector<int>			my;
	ft::vector<int>			tmp;
	ft::vector<int>			empty;

	real.push_back(26);
	real.push_back(24);
	real.push_back(22);
	real.push_back(225);
	real.push_back(5000);
	real.push_back(85);
	real.push_back(59);
	real.push_back(2);

	tp.push_back(16);
	tp.push_back(6);
	tp.push_back(1);
	tp.push_back(27);

	my.push_back(26);
	my.push_back(24);
	my.push_back(22);
	my.push_back(225);
	my.push_back(5000);
	my.push_back(85);
	my.push_back(59);
	my.push_back(2);

	tmp.push_back(16);
	tmp.push_back(6);
	tmp.push_back(1);
	tmp.push_back(27);

	std::cout << std::endl << "real :" << std::endl;
	// for (size_t i = 0; i < real.size(); i++)
	// 	std::cout << real.at(i) << std::endl;
	for (std::vector<int>::iterator it = real.begin(); it != real.end(); it++)
		std::cout << *it << " " << it.base() << std::endl;
	std::cout << "size : " << real.size() << " capacity : " << real.capacity() << std::endl;

	std::cout << std::endl << "My :" << std::endl;
	// // for (size_t i = 0; i < my.size(); i++)
	// // 	std::cout << my.at(i) << std::endl;
	for (ft::vector<int>::iterator it = my.begin(); it != my.end(); it++)
		std::cout << *it << " " << it.base() << std::endl;
	std::cout << "size : " << my.size() << " capacity : " << my.capacity() << std::endl;

	real.erase(real.begin() + 2, real.end() - 4);

	std::cout << std::endl << "real :" << std::endl;
	// for (size_t i = 0; i < real.size(); i++)
	// 	std::cout << real.at(i) << std::endl;
	for (std::vector<int>::iterator it = real.begin(); it != real.end(); it++)
		std::cout << *it << " " << it.base() << std::endl;
	std::cout << "size : " << real.size() << " capacity : " << real.capacity() << std::endl;

	my.erase(my.begin() + 2, my.end() - 4);

	std::cout << std::endl << "My :" << std::endl;
	// // for (size_t i = 0; i < my.size(); i++)
	// // 	std::cout << my.at(i) << std::endl;
	for (ft::vector<int>::iterator it = my.begin(); it != my.end(); it++)
		std::cout << *it << " " << it.base() << std::endl;
	std::cout << "size : " << my.size() << " capacity : " << my.capacity() << std::endl;

	real.resize(12);

	std::cout << std::endl << "real :" << std::endl;
	// for (size_t i = 0; i < real.size(); i++)
	// 	std::cout << real.at(i) << std::endl;
	for (std::vector<int>::iterator it = real.begin(); it != real.end(); it++)
		std::cout << *it << " " << it.base() << std::endl;
	std::cout << "size : " << real.size() << " capacity : " << real.capacity() << std::endl;

	my.resize(12);
	std::cout << std::endl << "My :" << std::endl;
	// // for (size_t i = 0; i < my.size(); i++)
	// // 	std::cout << my.at(i) << std::endl;
	for (ft::vector<int>::iterator it = my.begin(); it != my.end(); it++)
		std::cout << *it << " " << it.base() << std::endl;
	std::cout << "size : " << my.size() << " capacity : " << my.capacity() << std::endl;

}

// int main (void)
// {
// 	std::vector<int>			r_integer1;
// 	std::cout << r_integer1.size() << " & " << r_integer1.capacity() << std::endl;
// 	r_integer1.pop_back();
// 	std::cout << r_integer1.size() << " & " << r_integer1.capacity() << std::endl;

// }
