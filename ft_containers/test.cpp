#include <vector>
#include <iostream>

int main ()
{
    std::vector<int> vi;
	vi.push_back(0);
	vi.push_back(1);
	vi.push_back(2);
	vi.push_back(3);
	std::vector<int>::reverse_iterator r1(std::vector<int>::iterator vi);
    std::cout << "*r1 = " << *r1 << '\n';
}
