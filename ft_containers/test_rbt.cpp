#include <iostream>
#include "red_black_tree.hpp"
#include "pair.hpp"
int main(void)
{
	ft::RBTree<int, int>	first;

	for (int i = 0; i < 8; i++)
		first.insert(ft::make_pair(i, i));
	first.print();
	return 0;
}
