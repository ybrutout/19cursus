#include <iostream>
#include <vector>
#include "vector.hpp"

int		main(void)
{
	std::vector<int>			r_integer1(10, 8);
	std::vector<int> const		r_integer2(3, 9);
	std::vector<int>			r_integer3;
	std::vector<std::string>	r_string1(56, "coucou");
	std::vector<std::string>	r_string2;

	ft::vector<int>				my_integer1(10, 8);
	ft::vector<int>	const		my_integer2(3, 9);
	ft::vector<int>				my_integer3;
	ft::vector<std::string>		my_string1(56, "coucou");
	ft::vector<std::string>		my_string2;

	



	return 0;
}

// int main (void)
// {
// 	std::vector<int>			r_integer1;
// 	std::cout << r_integer1.size() << " & " << r_integer1.capacity() << std::endl;
// 	r_integer1.pop_back();
// 	std::cout << r_integer1.size() << " & " << r_integer1.capacity() << std::endl;

// }
