#include "binary_tree.hpp"
#include <string>
#include <iostream>
#include <vector>


int main(void)
{
	ft::Binary_Tree<int, int>		 first;

	first.insert(17, 17);
	first.insert(13, 13);
	first.insert(3, 3);
	first.insert(15, 15);
	first.insert(14, 14);
	first.insert(16, 16);
	first.insert(2, 2);
	first.insert(6, 6);
	first.insert(18, 18);
	first.print();
	first.erase(13);
	first.print();
	//first.clear();
	//first.print();


	ft::Binary_Tree<int,int>::iterator	ite;

	ite = first.begin();
	std::cout << first.begin()._node->value._first << std::endl;
	std::cout << first.end()._node->value._first << std::endl;
	for (size_t i = 0; ite._node->value._first != first.end()._node->value._first; i++, ++ite)
		std::cout << ite._node->value._first << " and " << first.end()._node->value._first <<  std::endl;
	std::cout << ite._node->value._first << " and " << first.end()._node->value._first <<  std::endl;
	std::cout << std::endl;
	for (size_t i = 0; ite._node->value._first != first.begin()._node->value._first; i++, --ite)
		std::cout << ite._node->value._first << std::endl;
	std::cout << ite._node->value._first << std::endl;
}
