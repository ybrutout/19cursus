#include <iostream>
#include <vector>
#include "vector.hpp"
#include <iterator>

int		main(void)
{
	std::vector<int>		real;
	ft::vector<int>			my;

	real.push_back(26);
	real.push_back(24);
	real.push_back(22);

	my.push_back(26);
	my.push_back(24);
	my.push_back(22);

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

	real.insert((real.begin() + 2), 5, 18);

	my.insert((my.begin() + 2), 5, 18);

	std::cout <<"Real :" << std::endl;
	for (std::vector<int>::iterator it = real.begin(); it != real.end(); it++)
		std::cout << *it << " " << it.base() << std::endl;
	// for (size_t i = 0; i < real.size(); i++)
	// 	std::cout << real.at(i) << std::endl;
	std::cout << std::endl << "My :" << std::endl;
	// for (size_t i = 0; i < my.size(); i++)
	// 	std::cout << my.at(i) << std::endl;
	for (ft::vector<int>::iterator it = my.begin(); it != my.end(); it++)
		std::cout << *it << " " << it.base() << std::endl;

}

// int main (void)
// {
// 	std::vector<int>			r_integer1;
// 	std::cout << r_integer1.size() << " & " << r_integer1.capacity() << std::endl;
// 	r_integer1.pop_back();
// 	std::cout << r_integer1.size() << " & " << r_integer1.capacity() << std::endl;

// }
