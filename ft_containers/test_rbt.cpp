#include <iostream>
#include "red_black_tree.hpp"
#include "pair.hpp"
int main(void)
{
	ft::RBTree<int, int>	first;

	for (int i = 0; i < 41; i++)
	{
		first.insert(ft::make_pair(i, i));
		//first.print();
	}
	first.print();
	for (int i = 41; i > -1; i--)
	{
		first.to_delete(ft::make_pair(i, i));
		first.print();
	}
	return 0;
}
