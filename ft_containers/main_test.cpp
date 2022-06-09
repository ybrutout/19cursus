#include <iostream>
#include <vector>
#include "vector.hpp"
#include <iterator>

int		main(void)
{
	std::vector<int>		real;
	std::vector<int>		tp;
	ft::vector<int>			my;
	ft::vector<int>			tmp;

	real.push_back(26);
	real.push_back(24);
	real.push_back(22);
	real.push_back(22);

	tp.push_back(16);
	tp.push_back(6);
	tp.push_back(1);
	tp.push_back(27);

	my.push_back(26);
	my.push_back(24);
	my.push_back(22);
	my.push_back(22);

	tmp.push_back(16);
	tmp.push_back(6);
	tmp.push_back(1);
	tmp.push_back(27);

	std::cout <<"Real :" << std::endl;
	// for (size_t i = 0; i < real.size(); i++)
	// 	std::cout << real.at(i) << std::endl;
	for (std::vector<int>::iterator it = real.begin(); it != real.end(); it++)
		std::cout << *it << " " << it.base() << std::endl;
	std::cout << std::endl << "My :" << std::endl;
	// for (size_t i = 0; i < my.size(); i++)
	// 	std::cout << my.at(i) << std::endl;
	for (ft::vector<int>::iterator it = my.begin(); it != my.end(); it++)
		std::cout << *it << " " << it.base() << std::endl;

	std::cout << std::endl;

	real.insert((real.begin() + 2), tp.begin(), tp.end());
	std::cout <<"Real :" << std::endl;
	for (std::vector<int>::iterator it = real.begin(); it != real.end(); it++)
		std::cout << *it << " " << it.base() << std::endl;
	std::cout << "size : " << real.size() << " capacity : " << real.capacity() << std::endl;
	// for (size_t i = 0; i < real.size(); i++)
	// 	std::cout << real.at(i) << std::endl;

	my.insert((my.begin() + 2), tmp.begin(), tmp.end());

	std::cout << std::endl << "My :" << std::endl;
	// for (size_t i = 0; i < my.size(); i++)
	// 	std::cout << my.at(i) << std::endl;
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
