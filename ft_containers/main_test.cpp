#include <iostream>
#include <vector>

int		main(void)
{
	std::vector<int>			essais(0, 8);

	std::cout << essais.capacity() << std::endl;

	return 0;
}
