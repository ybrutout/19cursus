#include "../ft_lib.hpp"

//hey

void    ft_cannonical_vector(void)
{
	/*Default Constructor*/
	std::cout << "**********TEST FOR THE CONSTRUCTOR**********" <<std::endl;
	std::cout << "-----Default-Constructor-----" << std::endl;
	
	ft::vector<int>     ft_vect_default;
	std::cout << "Size :" << ft_vect_default.size() << std::endl;
	std::cout << "Empty :" << ft_vect_default.empty() << std::endl;
	
	std::cout << "-----------------------------" << std::endl << std::endl;
	
	std::cout << "-------Fill-Constructor------" << std::endl;
	
	ft::vector<int>		ft_vect_fill(200, 16);
	std::cout << "Size :" << ft_vect_fill.size() << std::endl;
	std::cout << "Empty :" << ft_vect_fill.empty() << std::endl;
	std::cout << "At :" << ft_vect_fill[19] << std::endl;

	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "------Range-Constructor------" << std::endl;
	
	for (int i = 0; i < 100; i++)
		ft_vect_default.push_back(i);
	ft::vector<int>		ft_vect_range(ft_vect_default.begin(), --ft_vect_default.end());
	std::cout << "Size :" << ft_vect_range.size() << std::endl;
	std::cout << "Empty :" << ft_vect_range.empty() << std::endl;
	std::cout << "Default At :" << ft_vect_default[10] << std::endl;
	std::cout << "Range At :" << ft_vect_range[10] << std::endl;

	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "------Range-Constructor------" << std::endl;
	
	for (int i = 10000; i < 10100; i++)
		ft_vect_default.push_back(i);
	ft::vector<int>     ft_vect_copy(ft_vect_default);
	std::cout << "Size :" << ft_vect_copy.size() << std::endl;
	std::cout << "Empty :" << ft_vect_copy.empty() << std::endl;
	std::cout << "Default At :" << ft_vect_default[125] << std::endl;
	std::cout << "Copy At :" << ft_vect_copy[125] << std::endl;

	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "----------Opérateur=---------" << std::endl;
	
	ft_vect_range = ft_vect_copy;
	std::cout << "Size :" << ft_vect_range.size() << std::endl;
	std::cout << "Empty :" << ft_vect_range.empty() << std::endl;
	std::cout << "Range At :" << ft_vect_range[125] << std::endl;

	std::cout << "-----------------------------" << std::endl;
	std::cout << "********************************************" <<std::endl << std::endl;
}

void	ft_iterator_vector()
{
	ft::vector<int>		vect;
	for (int i = 0; i < 100; i++)
		vect.push_back(i);
	std::cout << "************TEST FOR THE ITERATOR***********" <<std::endl;

	std::cout << "------------Beguin-----------" << std::endl;
	std::cout << "Beguin :" << *(vect.begin()) << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "-------------End-------------" << std::endl;
	std::cout << "End :" << *(--vect.end()) << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "------------Rbegin-----------" << std::endl;
	std::cout << "Rbeguin :" << *(vect.rbegin()) << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "-------------Rend------------" << std::endl;
	std::cout << "Rend :" << *(--vect.rend()) << std::endl;
	std::cout << "-----------------------------" << std::endl;

	std::cout << "********************************************" <<std::endl << std::endl;
}

void	ft_capacity_vector()
{
	std::cout << "************TEST FOR THE CAPACITY***********" <<std::endl;
	ft::vector<int>		empty_vect;
	ft::vector<int>		big_vect;
	ft::vector<int>		small_vect;
	for (int i = 0; i < 100; i++)
		big_vect.push_back(i);
	for(int i = 0; i < 10; i++)
		small_vect.push_back(i);
	
	std::cout << "-------------Size------------" << std::endl;
	std::cout << "Empty size :" << empty_vect.size() << std::endl;
	std::cout << "Big size :" << big_vect.size() << std::endl;
	std::cout << "Small size :" << small_vect.size() << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "-------------Empty-----------" << std::endl;
	std::cout << "Empty empty :" << empty_vect.empty() << std::endl;
	std::cout << "Big empty :" << big_vect.empty() << std::endl;
	std::cout << "Small empty :" << small_vect.empty() << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "-----------Max-Size----------" << std::endl;
	std::cout << "Empty max_size :" << empty_vect.max_size() << std::endl;
	std::cout << "Big max_size :" << big_vect.max_size() << std::endl;
	std::cout << "Small max_size :" << small_vect.max_size() << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "------------Resize-----------" << std::endl;
	empty_vect.resize(50);
	big_vect.resize(50);
	small_vect.resize(50);
	std::cout << "Empty size :" << empty_vect.size() << " | Empty at :" << empty_vect.at(25) <<std::endl;
	std::cout << "Big size :" << big_vect.size() << " | Big at :" << big_vect.at(25) <<std::endl;
	std::cout << "Small size :" << small_vect.size() << " | Small at :" << small_vect.at(25) <<std::endl;
	ft::vector<int>	tmp_empty;
	tmp_empty.resize(10, 16);
	std::cout << "Tmp_empty size :" << tmp_empty.size() << " | Tmp_empty at :" << tmp_empty.at(5) <<std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "-----Capacity-&-Reserve------" << std::endl;
	std::cout << "Empty capacity :" << empty_vect.capacity() << std::endl;
	std::cout << "Big capacity :" << big_vect.capacity() << std::endl;
	std::cout << "Small capacity :" << small_vect.capacity() << std::endl;
	empty_vect.reserve(100);
	big_vect.reserve(100);
	small_vect.reserve(100);
	std::cout << "Empty capacity :" << empty_vect.capacity() << std::endl;
	std::cout << "Big capacity :" << big_vect.capacity() << std::endl;
	std::cout << "Small capacity :" << small_vect.capacity() << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "********************************************" <<std::endl << std::endl;
}

void	ft_access_vector()
{
	std::cout << "************TEST FOR THE CAPACITY***********" <<std::endl;

	ft::vector<int>		vect;
	for(int i = 0; i < 100; i++)
		vect.push_back(i * 10);
	std::cout << "----------Operator[]---------" << std::endl;
	std::cout << vect[6] << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "--------------At-------------" << std::endl;
	std::cout << vect.at(7) << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "------------Front------------" << std::endl;
	std::cout << vect.front() << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "-------------Back------------" << std::endl;
	std::cout << vect.back() << std::endl;
	std::cout << "-----------------------------" << std::endl;

	std::cout << "********************************************" <<std::endl << std::endl;
}

void	ft_modifiers_vector()
{
	ft::vector<int>		vect;
	for(int i = 0; i < 100; i++)
		vect.push_back(i + 2);
	ft::vector<int>		empty;
	ft::vector<int>		big;
	ft::vector<int>		small;
	for(int i = 0; i < 10; i++)
		small.push_back(i);
	for(int i = 0; i < 10000; i++)
		big.push_back(i + 1);
	std::cout << "************TEST FOR THE MODIFIERS**********" <<std::endl;

	std::cout << "------------Assign----------" << std::endl;
	std::cout << "Vect size : " << vect.size() << "		| Vect at[5] : " << vect.at(5) << std::endl;
	std::cout << "Empty size : " << empty.size() << std::endl;
	std::cout << "Small size : " << small.size() << "		| Small at[5] : " << small.at(5) << std::endl;
	std::cout << "Big size : " << big.size() << "	| Big at[5] : " << big.at(5) << std::endl << std::endl;

	vect.assign(empty.begin(), empty.end());
	empty.assign(small.begin(), small.end());
	std::cout << "Vect size : " << vect.size() << std::endl;
	std::cout << "Empty size : " << empty.size() << "		| Empty at[5] : " << empty.at(5) << std::endl << std::endl;

	vect.assign(small.begin() + 2, small.end() - 2);
	std::cout << "Vect size : " << vect.size() << "		| Vect at[5] : " << vect.at(5) << std::endl << std::endl;

	empty.assign(60, 16);
	std::cout << "Empty size : " << empty.size() << "		| Empty at[5] : " << empty.at(5) << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "-----------Push_Back---------" << std::endl;
	std::cout << "Last element in vect : " << *(vect.rbegin()) << std::endl;
	std::cout << "Last element in empty : " << *(empty.rbegin()) << std::endl;
	std::cout << "Last element in small : " << *(small.rbegin()) << std::endl;
	std::cout << "Last element in big : " << *(big.rbegin()) << std::endl << std::endl;
	vect.push_back(16);
	empty.push_back(6);
	small.push_back(1);
	big.push_back(27);
	std::cout << "Last element in vect : " << *(vect.rbegin()) << std::endl;
	std::cout << "Last element in empty : " << *(empty.rbegin()) << std::endl;
	std::cout << "Last element in small : " << *(small.rbegin()) << std::endl;
	std::cout << "Last element in big : " << *(big.rbegin()) << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "-----------Pop_Back----------" << std::endl;
	std::cout << "Last element in vect : " << *(vect.rbegin()) << std::endl;
	std::cout << "Last element in empty : " << *(empty.rbegin()) << std::endl;
	std::cout << "Last element in small : " << *(small.rbegin()) << std::endl;
	std::cout << "Last element in big : " << *(big.rbegin()) << std::endl << std::endl;
	vect.pop_back();
	empty.pop_back();
	small.pop_back();
	big.pop_back();
	std::cout << "Last element in vect : " << *(vect.rbegin()) << std::endl;
	std::cout << "Last element in empty : " << *(empty.rbegin()) << std::endl;
	std::cout << "Last element in small : " << *(small.rbegin()) << std::endl;
	std::cout << "Last element in big : " << *(big.rbegin()) << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "------------Insert-----------" << std::endl;
	std::cout << "First element in vect : " << *(vect.begin()) << " | vect size : " << vect.size() <<std::endl;
	std::cout << "First element in empty : " << *(empty.begin()) << " | empty size : " << empty.size() <<std::endl;
	std::cout << "First element in small : " << *(small.begin()) << " | small size : " << small.size() <<std::endl;
	std::cout << "First element in big : " << *(big.begin()) << " | big size : " << big.size() <<std::endl << std::endl;
	vect.insert(vect.begin(), 2);
	empty.insert(empty.begin(), 10, 2);
	small.insert(small.begin(), big.begin(), big.end());
	std::cout << "First element in vect : " << *(vect.begin()) << " | vect size : " << vect.size() <<std::endl;
	std::cout << "First element in empty : " << *(empty.begin()) << " | empty size : " << empty.size() <<std::endl;
	std::cout << "First element in small : " << *(small.begin()) << " | small size : " << small.size() <<std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "------------Erase------------" << std::endl;
	std::cout << "First element in vect : " << *(vect.begin()) << " | vect size : " << vect.size() <<std::endl;
	std::cout << "First element in empty : " << *(empty.begin()) << " | empty size : " << empty.size() <<std::endl;
	std::cout << "First element in small : " << *(small.begin()) << " | small size : " << small.size() <<std::endl;
	std::cout << "First element in big : " << *(big.begin()) << " | big size : " << big.size() <<std::endl << std::endl;
	vect.erase(vect.begin());
	empty.erase(empty.begin(), --empty.end());
	small.erase(small.begin(), small.end() - 10);
	big.erase(big.begin(), big.begin() + 100);
	std::cout << "First element in vect : " << *(vect.begin()) << " | vect size : " << vect.size() <<std::endl;
	std::cout << "First element in empty : " << *(empty.begin()) << " | empty size : " << empty.size() <<std::endl;
	std::cout << "First element in small : " << *(small.begin()) << " | small size : " << small.size() <<std::endl;
	std::cout << "First element in big : " << *(big.begin()) << " | big size : " << big.size() <<std::endl << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "-------------Clear-----------" << std::endl;
	std::cout << "Vect size : " << vect.size() << std::endl;
	std::cout << "Empty size : " << empty.size() << std::endl;
	std::cout << "Small size : " << small.size() << std::endl;
	std::cout << "Big size : " << big.size() << std::endl << std::endl;
	vect.clear();
	empty.clear();
	small.clear();
	big.clear();
	std::cout << "Vect size : " << vect.size() << std::endl;
	std::cout << "Empty size : " << empty.size() << std::endl;
	std::cout << "Small size : " << small.size() << std::endl;
	std::cout << "Big size : " << big.size() << std::endl;
	std::cout << "-----------------------------" << std::endl;

	std::cout << "-------------Swap------------" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		small.push_back(i);
		big.push_back(i * 2);
	}
	ft::vector<int>::iterator	it = small.begin();
	ft::vector<int>::iterator	ite = big.begin();
	std::cout << "  small	 	|	big	" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	for(int i = 0; i < 5; i++, it++, ite++)
		std::cout << "	" << *it << "	|	" << *ite << std::endl;
	std::cout << std::endl;

	small.swap(big);

	it = small.begin();
	ite = big.begin();
	std::cout << "  small	 	|	big	" << std::endl;
	std::cout << "---------------------------------" << std::endl;
	for(int i = 0; i < 5; i++, it++, ite++)
		std::cout << "	" << *it << "	|	" << *ite << std::endl;
	std::cout << std::endl;

	std::cout << "-----------------------------" << std::endl;

	std::cout << "********************************************" <<std::endl << std::endl;
}

void	ft_relationnel_operator()
{
	ft::vector<int>		vect;		
	ft::vector<int>		vect1;
	ft::vector<int>		vect2;

	for(int i = 0; i < 10; i++)
	{
		vect1.push_back(i);
		vect.push_back(i);
	}	
	for(int i = 100; i < 200; i++)
		vect2.push_back(i);

	ft::vector<int>::iterator	it = vect.begin();
	ft::vector<int>::iterator	ite = vect1.begin();
	ft::vector<int>::iterator	iter = vect2.begin();

	std::cout << "	vect	|	vect1	|	vect2" << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	for(int i = 0; i < 5; i++, it++, ite++, iter++)
		std::cout << "	" << *it << "	|	" << *ite << "	|	" << *iter << std::endl;
	std::cout << "--------------------------------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << " == " << (vect == vect1) << " | " << (vect == vect2) << std::endl;
	std::cout << " != " << (vect != vect1) << " | " << (vect != vect2) << std::endl;
	std::cout << " > " << (vect > vect1) << " | " << (vect > vect2) << std::endl;
	std::cout << " < " << (vect < vect1) << " | " << (vect < vect2) << std::endl;
	std::cout << " <= " << (vect <= vect1) << " | " << (vect <= vect2) << std::endl;
	std::cout << " >= " << (vect >= vect1) << " | " << (vect >= vect2) << std::endl;
}


int vector_test()
{
	ft_cannonical_vector();
	ft_iterator_vector();
	ft_capacity_vector();
	ft_access_vector();
	ft_modifiers_vector();
	ft_relationnel_operator();
	return 0;
}