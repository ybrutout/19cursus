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
	first.print();
	first.erase(13);

	first.print();
}
