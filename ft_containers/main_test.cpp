#include <iostream>
#include <vector>
#include "vector.hpp"
#include <iterator>

// TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin(), ite = vct.end();

// 	std::cout << "len: " << (ite - it) << std::endl;
// 	for (; it != ite; ++it)
// 		*it = (ite - it);

// 	it = vct.begin();
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_range(it, --(--ite));
// 	for (int i = 0; it != ite; ++it)
// 		*it = ++i * 5;

// 	it = vct.begin();
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct_copy(vct);
// 	for (int i = 0; it != ite; ++it)
// 		*it = ++i * 7;
// 	vct_copy.push_back(42);
// 	vct_copy.push_back(21);
/***************************************************************************************************/
// 	std::cout << "\t-- PART ONE --" << std::endl;
// 	printSize(vct);
// 	printSize(vct_range);
// 	printSize(vct_copy);

// 	vct = vct_copy;
// 	vct_copy = vct_range;
// 	vct_range.clear();

// 	std::cout << "\t-- PART TWO --" << std::endl;
// 	printSize(vct);
// 	printSize(vct_range);
// 	printSize(vct_copy);
// 	return (0);

int		main(void)
{
	std::vector<int>	r_vct(5);
	ft::vector<int>		my_vct(5);

	std::vector<int>::iterator r_it = r_vct.begin(), r_ite = r_vct.end();
	ft::vector<int>::iterator my_it = my_vct.begin(), my_ite = my_vct.end();

	std::cout << "len: " << (r_ite - r_it) << std::endl;
	std::cout << "len: " << (my_ite - my_it) << std::endl;

	std::vector<int>	r_vct_range(r_it, --(--r_ite));
	for (int i = 0; r_it != r_ite; r_it++)
		*r_it = ++i * 5;
	std::cout << "vct_range " << std::endl;
	for (size_t i = 0; i < r_vct_range.size(); i++)
		std::cout << "- " << r_vct_range[i] << std::endl;
	ft::vector<int>	my_vct_range(my_it, --(--my_ite));
	for (int i = 0; my_it != my_ite; my_it++)
		*my_it = ++i * 5;
	std::cout << "my_vct_range " << std::endl;
	for (size_t i = 0; i < my_vct_range.size(); i++)
		std::cout << "- " << my_vct_range[i] << std::endl;
	std::cout << "*********************************************************" << std::endl;
	r_it = r_vct.begin();
	std::vector<int>	r_vct_copy(r_vct);
	for (int i = 0; r_it != r_ite; ++r_it)
		*r_it = ++i * 7;
	r_vct_copy.push_back(42);
	r_vct_copy.push_back(21);
	std::cout << "r_vct " << std::endl;
	for (size_t i = 0; i < r_vct.size(); i++)
		std::cout << "- " << r_vct[i] << std::endl;
	std::cout << "r_vct_copy " << std::endl;
	for (size_t i = 0; i < r_vct_copy.size(); i++)
		std::cout << "- " << r_vct_copy[i] << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;
	my_it = my_vct.begin();
	ft::vector<int>	my_vct_copy(my_vct);
	for (int i = 0; my_it != my_ite; ++my_it)
		*my_it = ++i * 7;
	my_vct_copy.push_back(42);
	my_vct_copy.push_back(21);
	std::cout << "my_vct " << std::endl;
	for (size_t i = 0; i < my_vct.size(); i++)
		std::cout << "- " << my_vct[i] << std::endl;
	std::cout << "my_vct_copy " << std::endl;
	for (size_t i = 0; i < my_vct_copy.size(); i++)
		std::cout << "- " << my_vct_copy[i] << std::endl;
	std::cout << "*********************************************************" << std::endl;
	std::cout << "r_vct " << std::endl;
	std::cout << "size : " << r_vct.size() << std::endl << "capacity : " << r_vct.capacity() << std::endl;
	for (size_t i = 0; i < r_vct.size(); i++)
		std::cout << "- " << r_vct[i] << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << "my_vct " << std::endl;
	std::cout << "size : " << my_vct.size() << std::endl << "capacity : " << my_vct.capacity() << std::endl;
	for (size_t i = 0; i < my_vct.size(); i++)
		std::cout << "- " << my_vct[i] << std::endl;
	std::cout << "*********************************************************" << std::endl;
	std::cout << "*********************************************************" << std::endl;
	std::cout << "r_vct_range " << std::endl;
	std::cout << "size : " << r_vct_range.size() << std::endl << "capacity : " << r_vct_range.capacity() << std::endl;
	for (size_t i = 0; i < r_vct_range.size(); i++)
		std::cout << "- " << r_vct_range[i] << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << "my_vct_range " << std::endl;
	std::cout << "size : " << my_vct_range.size() << std::endl << "capacity : " << my_vct_range.capacity() << std::endl;
	for (size_t i = 0; i < my_vct_range.size(); i++)
		std::cout << "- " << my_vct_range[i] << std::endl;
	std::cout << "*********************************************************" << std::endl;
	std::cout << "*********************************************************" << std::endl;
	std::cout << "r_vct_copy " << std::endl;
	std::cout << "size : " << r_vct_copy.size() << std::endl << "capacity : " << r_vct_copy.capacity() << std::endl;
	for (size_t i = 0; i < r_vct_copy.size(); i++)
		std::cout << "- " << r_vct_copy[i] << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << "my_vct_copy " << std::endl;
	std::cout << "size : " << my_vct_copy.size() << std::endl << "capacity : " << my_vct_copy.capacity() << std::endl;
	for (size_t i = 0; i < my_vct_copy.size(); i++)
		std::cout << "- " << my_vct_copy[i] << std::endl;
	std::cout << "*********************************************************" << std::endl;

}

// int main (void)
// {
// 	std::vector<int>			r_integer1;
// 	std::cout << r_integer1.size() << " & " << r_integer1.capacity() << std::endl;
// 	r_integer1.pop_back();
// 	std::cout << r_integer1.size() << " & " << r_integer1.capacity() << std::endl;

// }



	/*Test pour swap*/
	// std::cout << "Before Swap " << std::endl;
	// std::cout << "REAL : " << std::endl;
	// std::cout << "size : " << real.size() << std::endl;
	// std::cout << "capacity : " << real.capacity() << std::endl;
	// std::cout << "max_size : " << real.max_size() << std::endl;
	// std::cout << "Content is : " << std::endl;
	// for (size_t i = 0; i < real.size(); i++)
	// 	std::cout << "- " << real[i] << std::endl;
	// std::cout << "*********************************************************" << std::endl;
	// std::cout << "TP : " << std::endl;
	// std::cout << "size : " << tp.size() << std::endl;
	// std::cout << "capacity : " << tp.capacity() << std::endl;
	// std::cout << "max_size : " << tp.max_size() << std::endl;
	// std::cout << "Content is : " << std::endl;
	// for (size_t i = 0; i < tp.size(); i++)
	// 	std::cout << "- " << tp[i] << std::endl;
	// std::cout << "*********************************************************" << std::endl;
	// std::cout << "MY : " << std::endl;
	// std::cout << "size : " << my.size() << std::endl;
	// std::cout << "capacity : " << my.capacity() << std::endl;
	// std::cout << "max_size : " << my.max_size() << std::endl;
	// std::cout << "Content is : " << std::endl;
	// for (size_t i = 0; i < my.size(); i++)
	// 	std::cout << "- " << my[i] << std::endl;
	// std::cout << "*********************************************************" << std::endl;
	// std::cout << "TMP : " << std::endl;
	// std::cout << "size : " << tmp.size() << std::endl;
	// std::cout << "capacity : " << tmp.capacity() << std::endl;
	// std::cout << "max_size : " << tmp.max_size() << std::endl;
	// std::cout << "Content is : " << std::endl;
	// for (size_t i = 0; i < tmp.size(); i++)
	// 	std::cout << "- " << tmp[i] << std::endl;
	// std::cout << "*********************************************************" << std::endl << std::endl << std::endl;

	// real.swap(tp);
	// my.swap(tmp);

	// std::cout << "AFTER SWAP " << std::endl;
	// std::cout << "REAL : " << std::endl;
	// std::cout << "size : " << real.size() << std::endl;
	// std::cout << "capacity : " << real.capacity() << std::endl;
	// std::cout << "max_size : " << real.max_size() << std::endl;
	// std::cout << "Content is : " << std::endl;
	// for (size_t i = 0; i < real.size(); i++)
	// 	std::cout << "- " << real[i] << std::endl;
	// std::cout << "*********************************************************" << std::endl;
	// std::cout << "TP : " << std::endl;
	// std::cout << "size : " << tp.size() << std::endl;
	// std::cout << "capacity : " << tp.capacity() << std::endl;
	// std::cout << "max_size : " << tp.max_size() << std::endl;
	// std::cout << "Content is : " << std::endl;
	// for (size_t i = 0; i < tp.size(); i++)
	// 	std::cout << "- " << tp[i] << std::endl;
	// std::cout << "*********************************************************" << std::endl;
	// std::cout << "MY : " << std::endl;
	// std::cout << "size : " << my.size() << std::endl;
	// std::cout << "capacity : " << my.capacity() << std::endl;
	// std::cout << "max_size : " << my.max_size() << std::endl;
	// std::cout << "Content is : " << std::endl;
	// for (size_t i = 0; i < my.size(); i++)
	// 	std::cout << "- " << my[i] << std::endl;
	// std::cout << "*********************************************************" << std::endl;
	// std::cout << "TMP : " << std::endl;
	// std::cout << "size : " << tmp.size() << std::endl;
	// std::cout << "capacity : " << tmp.capacity() << std::endl;
	// std::cout << "max_size : " << tmp.max_size() << std::endl;
	// std::cout << "Content is : " << std::endl;
	// for (size_t i = 0; i < tmp.size(); i++)
	// 	std::cout << "- " << tmp[i] << std::endl;
	// std::cout << "*********************************************************" << std::endl;

	// std::cout << "Iterator : " << std::endl;
	// std::cout << (it_my == tmp.begin()) << std::endl;
	// std::cout << (it_tmp == my.begin()) << std::endl;
	// std::cout << my.begin().base() << std::endl;
	// std::cout << it_tmp.base() << std::endl;
	// std::cout << tmp.begin().base() << std::endl;
	// std::cout << it_my.base() << std::endl;
