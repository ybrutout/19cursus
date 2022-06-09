#include "vector.hpp"

int		main(void)
{
	ft::vector<int> vct(7);
	ft::vector<int> vct_two(4);
	ft::vector<int> vct_three;
	ft::vector<int> vct_four;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;

	vct_three.assign(vct.begin(), vct.end());
	vct.assign(vct_two.begin(), vct_two.end());
	vct_two.assign(2, 42);
	vct_four.assign(4, 21);

	std::cout << "\t### After assign(): ###" << std::endl;

	std::cout << std::endl << "vct_three :" << std::endl;
	for (ft::vector<int>::iterator it = vct_three.begin(); it != vct_three.end(); it++)
		std::cout << *it << " " << it.base() << std::endl;
	std::cout << "size : " << vct_three.size() << " capacity : " << vct_three.capacity() << std::endl;

	std::cout << std::endl << "vct :" << std::endl;
	for (ft::vector<int>::iterator it = vct.begin(); it != vct.end(); it++)
		std::cout << *it << " " << it.base() << std::endl;
	std::cout << "size : " << vct.size() << " capacity : " << vct.capacity() << std::endl;

	std::cout << std::endl << "vct_two :" << std::endl;
	for (ft::vector<int>::iterator it = vct_two.begin(); it != vct_two.end(); it++)
		std::cout << *it << " " << it.base() << std::endl;
	std::cout << "size : " << vct_two.size() << " capacity : " << vct_two.capacity() << std::endl;

	std::cout << std::endl << "vct_four :" << std::endl;
	for (ft::vector<int>::iterator it = vct_four.begin(); it != vct_four.end(); it++)
		std::cout << *it << " " << it.base() << std::endl;
	std::cout << "size : " << vct_four.size() << " capacity : " << vct_four.capacity() << std::endl;

	vct_four.assign(6, 84);
	std::cout << std::endl << "vct_four :" << std::endl;
	for (ft::vector<int>::iterator it = vct_four.begin(); it != vct_four.end(); it++)
		std::cout << *it << " " << it.base() << std::endl;
	std::cout << "size : " << vct_four.size() << " capacity : " << vct_four.capacity() << std::endl;


	std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

	vct.assign(5, 53);
	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

	std::cout << std::endl << "vct :" << std::endl;
	for (ft::vector<int>::iterator it = vct.begin(); it != vct.end(); it++)
		std::cout << *it << " " << it.base() << std::endl;
	std::cout << "size : " << vct.size() << " capacity : " << vct.capacity() << std::endl;

	std::cout << std::endl << "vct_two :" << std::endl;
	for (ft::vector<int>::iterator it = vct_two.begin(); it != vct_two.end(); it++)
		std::cout << *it << " " << it.base() << std::endl;
	std::cout << "size : " << vct_two.size() << " capacity : " << vct_two.capacity() << std::endl;


	return (0);
}
