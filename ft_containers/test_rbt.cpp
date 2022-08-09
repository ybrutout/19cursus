#include <iostream>
#include "red_black_tree.hpp"
#include "pair.hpp"
int main(void)
{
	ft::RBTree<int, int>	first;

	for (int i = 0; i < 41; i++)
		first.insert(ft::make_pair(i, i));
	first.insert(ft::make_pair(10, 10));
	first.print();
	for (int i = 40; i > 0; i--)
	{
		first.to_delete(ft::make_pair(i, i));
		first.print();
	}
	return 0;
}
