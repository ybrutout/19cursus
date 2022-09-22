#include <iostream>
#include "map.hpp"
#include "red_black_tree.hpp"
#include "pair.hpp"

int main(void)
{
	ft::map<int, int>	first_map;
	ft::pair<ft::map<int, int>::iterator, bool>	p;
	ft::map<int,int>::iterator	it;
	ft::map<int,int>::iterator	itc;
	ft::map<int,int>::iterator	ite;
	// ft::map<int, int>	second;
	// ft::map<int, int>	empty;
	ft::map<int, int>::allocator_type	all;

	for (size_t i = 0; i < 15; i++)
		first_map.insert(ft::make_pair(i, i));
	ft::map<int, int> second(first_map.begin(), first_map.end());
	first_map.get_tree()->print();
	second.get_tree()->print();
	second.insert(ft::make_pair(-2, -2));
	first_map.insert(ft::make_pair(100, 100));
	first_map.get_tree()->print();
	second.get_tree()->print();
	// first_map.erase(first_map.begin());
	// std::cout << empty.size() << std::endl;
	// std::cout << first_map.size() << std::endl;
	// std::cout << empty.max_size() << std::endl;
	// std::cout << first_map.max_size() << std::endl;
	// all = first_map.get_allocator();
	return 0;
}
