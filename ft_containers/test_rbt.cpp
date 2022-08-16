#include <iostream>
#include "map.hpp"
#include "red_black_tree.hpp"
#include "pair.hpp"

// int main(void)
// {
// 	ft::map<int, int>	first_map;
// 	ft::pair<ft::map<int, int>::iterator, bool>	p;
// 	ft::map<int,int>::iterator	it;
// 	ft::map<int,int>::iterator	itc;
// 	ft::map<int,int>::iterator	ite;
// 	ft::map<int, int>	second;
// 	// size_t				ret;

// 	for (size_t i = 0; i < 15; i++)
// 		first_map.insert(ft::make_pair(i, i));
// 	for (size_t i = 100; i < 115; i++)
// 		second.insert(ft::make_pair(i, i));
// 	first_map.swap(second);
// 	std::cout << first_map.begin()._node->value.first << std::endl;
// 	std::cout << second.begin()._node->value.first << std::endl;
// 	return 0;
// }


int		main(void)
{
	ft::pair<ft::RBTree<int,int>::iterator, bool>	ret;
	ft::RBTree<int, int>							tree;
	ft::RBTree<int, int>::iterator					it;
	//size_t	tmp;

	for(size_t i = 1; i < 21; i++)
	{
		ret = tree.insert(ft::make_pair(i, i));
	}
	it = tree.RBTMaxVal();
	for (size_t i = 22; i > 0; i--)
	{
		// std::cout << "IT->" << i << " == " << (*it).value.first << std::endl;
		it--;
	}
	// tree.print();
	ft::RBTree<int, int>							second_tree(tree);
	//second_tree.print();

		// ret = tree.insert(ft::make_pair(5, 5));
		// std::cout << "Ret_first == " << (ret.first)._node->value.first << " | Ret_second == " << ret.second << std::endl;
	return 0;
}

	// /*Insert*/
	// for(size_t i = 0; i < 20; i++)
	// {
	// 	p = first_map.insert(ft::make_pair(i, i));
	// 	// std::cout << "P_first == " << p.first._node->value.first << " P_second == " << p.second << std::endl;
	// }
	// // p = first_map.insert(ft::make_pair(5, 5));
	// // 	std::cout << "P_first == " << p.first._node->value.first << " P_second == " << p.second << std::endl;
	// /*Begin*/
	// // it = first_map.begin();
	// // ite = first_map.begin();
	// // for (size_t i = 0; i < 6; i++)
	// // 	ite++;
	// // /*Insert*/
	// // second.insert(it, ite);

	// it = first_map.begin();
	// it++;
	// it++;
	// itc = it;

	// /*Erase*/
	// for (size_t i = 15; i > 9; i--)
	// {
	// 	ret = first_map.erase(i);
	// 	// std::cout << "Ret == " << ret << std::endl;
	// }
	// ret = first_map.erase(96);
	// // std::cout << "Ret == " << ret << std::endl;

	// it = first_map.begin();
	// first_map.erase(it);

	// //std::cout << "HEY == " << (*itc).right->value.first << std::endl;

	// it = first_map.begin();
	// it++;
	// ite = it;
	// for (size_t i = 0; i < 5; i++)
	// {
	//  	ite++;
	// }
	// first_map.erase(it, ite);
