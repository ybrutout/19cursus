#include "map.hpp"
#include "binary_tree.hpp"
#include "pair.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <map>

int main(void)
{
	ft::Binary_Tree<int, int>			first;
	ft::Binary_Tree<int, int>			sec;

	first.insert(ft::make_pair(17,17));
	first.insert(ft::make_pair(13,13));
	first.insert(ft::make_pair(3, 3));
	first.insert(ft::make_pair(15, 15));
	first.insert(ft::make_pair(14, 14));
	first.insert(ft::make_pair(16, 16));
	first.insert(ft::make_pair(2, 2));
	first.insert(ft::make_pair(6, 6));
	first.insert(ft::make_pair(18, 18));
	first.insert(ft::make_pair(15, 15));
	first.print();
	sec = first;

	first.insert(ft::make_pair(21, 21));
	first.print();

	sec.print();
}

// int 	main()
// {
// 	std::map<int, int>		first;

// 	first.insert(std::make_pair(17,17));
// 	first.insert(std::make_pair(13,13));
// 	first.insert(std::make_pair(3, 3));
// 	first.insert(std::make_pair(15, 15));
// 	first.insert(std::make_pair(14, 14));
// 	first.insert(std::make_pair(16, 16));
// 	first.insert(std::make_pair(2, 2));
// 	first.insert(std::make_pair(6, 6));
// 	first.insert(std::make_pair(18, 18));
// 	first.insert(std::make_pair(15, 15));

// }
