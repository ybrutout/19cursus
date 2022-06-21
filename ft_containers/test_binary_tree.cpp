#include "binary_tree.hpp"
#include <string>
#include <iostream>
#include <vector>


int main(void)
{
	ft::Binary_Tree<int, std::string>		 first;

	first.insert(3, "hey");
	first.insert(5, "comment");
	first.insert(1, "ca");
	first.insert(4, "va");
	first.insert(4, "moi");
	first.insert(4, "ca");
	first.insert(4, "va");
	first.print();
}
