#include "../ft_lib.hpp"

void	ft_cannonical_map()
{
	std::cout << "**********TEST FOR THE CONSTRUCTOR**********" <<std::endl;
	std::cout << "-----Default-Constructor-----" << std::endl;
	ft::map<int, int>		empty;
	std::cout << empty.size() << " | " << empty.empty() << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "------Range-Constructor------" << std::endl;
	for(int i = 0; i < 50; i++)
		empty.insert(ft::make_pair(i, i+ 1));
	ft::map<int, int>		range(empty.begin(), empty.end());
	std::cout << range.size() << " | " << range.empty() << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "-------Copy-Constructor------" << std::endl;
	ft::map<int, int>		copy(range);
	std::cout << copy.size() << " | " << copy.empty() << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "----------Operator=----------" << std::endl;
	copy.insert(ft::make_pair(105, 12));
	std::cout << range.size() << std::endl;
	std::cout << copy.size() << std::endl << std::endl;
	range = copy;
	std::cout << range.size() << std::endl;
	std::cout << copy.size() << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;
	std::cout << "********************************************" <<std::endl << std::endl;
}

void	ft_iterator_map()
{
	ft::map<int, int>		map;
	for (int i = 0; i < 100; i++)
		map.insert(ft::make_pair(i, i));
	std::cout << "************TEST FOR THE ITERATOR***********" <<std::endl;

	std::cout << "------------Beguin-----------" << std::endl;
	std::cout << "Beguin :" << (map.begin())->first << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "-------------End-------------" << std::endl;
	std::cout << "End :" << (--map.end())->first << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "------------Rbegin-----------" << std::endl;
	std::cout << "Rbeguin :" << (map.rbegin())->first << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "-------------Rend------------" << std::endl;
	std::cout << "Rend :" << (--map.rend())->first << std::endl;
	std::cout << "-----------------------------" << std::endl;

	std::cout << "********************************************" <<std::endl << std::endl;
}

void	ft_capacity_map()
{
	ft::map<int, int>	map;
	ft::map<int, int>	map1;
	ft::map<int, int>	map2;

	for(int i = 0; i < 100; i++)
		map1.insert(ft::make_pair(i, i));
	for(int i = 100; i < 150; i++)
		map2.insert(ft::make_pair(i, i));
	std::cout << "Map size : " << map.size() << " | empty : " << map.empty() << " | max_size : " << map.max_size() << std::endl; 
	std::cout << "Map1 size : " << map1.size() << " | empty : " << map1.empty() << " | max_size : " << map1.max_size() << std::endl; 
	std::cout << "Map2 size : " << map2.size() << " | empty : " << map2.empty() << " | max_size : " << map2.max_size() << std::endl << std::endl;
}

void	ft_access_map()
{
	ft::map<int, int>		map;
	ft::map<int, int>		map1;
	
	for(int i = 0; i < 100; i++)
		map.insert(ft::make_pair(i, i));
	for(int i = 100; i < 200; i++)
		map1.insert(ft::make_pair(i, i));
	
	std::cout << "map[18] : " << map[18] << std::endl;
	std::cout << "map1[152] : " << map1[152] << std::endl << std::endl;
}

void	ft_modifiers_map()
{
	/*A montrer avec la fonction print()*/
	ft::map<int, int>		map;
	ft::map<int, int>		map1;
	ft::map<int, int>		map2;

	std::cout << "------------Insert-----------" << std::endl;
	for(int i = 0; i < 100; i++)
		map.insert(ft::make_pair(i, i));
	map1.insert(map.begin(), map.end());
	map2.insert(++(map.begin()), --(map.end()));
	std::cout << "Map size : " << map.size() << std::endl; 
	std::cout << "Map1 size : " << map1.size() << std::endl; 
	std::cout << "Map2 size : " << map2.size() << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "------------Erase------------" << std::endl;
	map.erase(map.begin());
	map1.erase(24);
	map2.erase(++(map2.begin()), --(map2.end()));
	std::cout << "Map size : " << map.size() << std::endl; 
	std::cout << "Map1 size : " << map1.size() << std::endl; 
	std::cout << "Map2 size : " << map2.size() << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "-------------Swap------------" << std::endl;
	ft::map<int, int>	swap1;
	ft::map<int, int>	swap2;

	for(int i = 0; i < 10; i++)
		swap1.insert(ft::make_pair(i, i));
	
	for(int i = 0; i < 100; i++)
		swap2.insert(ft::make_pair(i, i));
	std::cout << "Swap1 size : " << swap1.size() << std::endl; 
	std::cout << "Swap2 size : " << swap2.size() << std::endl << std::endl;
	swap1.swap(swap2);
	std::cout << "Swap1 size : " << swap1.size() << std::endl; 
	std::cout << "Swap2 size : " << swap2.size() << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;

	std::cout << "------------Clear------------" << std::endl;
	swap1.clear();
	swap2.clear();
	std::cout << "Swap1 size : " << swap1.size() << std::endl; 
	std::cout << "Swap2 size : " << swap2.size() << std::endl;
	std::cout << "-----------------------------" << std::endl << std::endl;
}

void	ft_operation_map()
{
	ft::map<int, int>	map;

	for(int i = 0; i < 100; i++)
		map.insert(ft::make_pair(i, i));
	
	std::cout << "Map find : " << map.find(12)->first << " | ";
	if (map.find(1526) == map.end())
		std::cout << "_end" << std::endl;
	else
		std::cout << (map.find(1526))->first << std::endl;

	std::cout << "Map find : " << map.count(12) << " | " << map.count(1526) << std::endl;
	
	std::cout << "Map find : " << map.lower_bound(12)->first << " | ";
	if (map.lower_bound(1526) == map.end())
		std::cout << "_end" << std::endl;
	else
		std::cout << (map.lower_bound(1526))->first << std::endl;
	
	std::cout << "Map find : " << map.upper_bound(12)->first << " | ";
	if (map.upper_bound(1526) == map.end())
		std::cout << "_end" << std::endl;
	else
		std::cout << (map.upper_bound(1526))->first << std::endl;

	std::cout << "Map find : " << (map.equal_range(12)).first->first << " | ";
	if (map.equal_range(1526).first == map.end())
		std::cout << "_end" << std::endl;
	else
		std::cout << (map.equal_range(1526)).first->first << std::endl;
}

void	ft_relationnel_operator_map()
{
	ft::map<int, int>	m;
	ft::map<int, int>	m2;
	ft::map<int, int>	m3;

	for (int i = 0; i < 100; i++)
		m.insert(ft::make_pair(rand() % 100, rand() % 100));
	for (int i = 0; i < 100; i++)
		m2.insert(ft::make_pair(rand() % 100, rand() % 100));
	for (int i = 0; i < 100; i++)
		m3.insert(ft::make_pair(rand() % 100, rand() % 100));
	
	std::cout << "1" << std::endl;
	std::cout << (m == m2) << (m2 == m3) << (m == m3) << std::endl;
	std::cout << (m != m2) << (m2 != m3) << (m != m3) << std::endl;
	std::cout << (m < m2) << (m2 < m3) << (m < m3) << std::endl;
	std::cout << (m <= m2) << (m2 <= m3) << (m <= m3) << std::endl;
	std::cout << (m > m2) << (m2 > m3) << (m > m3) << std::endl;
	std::cout << (m >= m2) << (m2 >= m3) << (m >= m3) << std::endl;
}

int map_test()
{
	ft_cannonical_map();
	ft_iterator_map();
	ft_capacity_map();
	ft_access_map();
	ft_modifiers_map();
	ft_operation_map();
	ft_relationnel_operator_map();
	return 0;
}