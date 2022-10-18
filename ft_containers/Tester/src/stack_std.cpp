#include "../std_lib.hpp"

int     stack_test(void)
{
	std::stack<int>      stack;
	std::stack<int>      stack1;
	std::stack<int>      stack2;

	for(int i = 0; i < 15; i++)
	{
		stack1.push(i + 10);
		stack2.push(i);
	}

	std::cout << "----------Empty----------" << std::endl;
	std::cout << "Stack " << stack.empty() << std::endl;
	std::cout << "Stack1 " << stack1.empty() << std::endl;
	std::cout << "Stack2 " << stack2.empty() << std::endl;
	std::cout << "-------------------------" << std::endl << std::endl;

	std::cout << "-----------Size----------" << std::endl;
	std::cout << "Stack " << stack.size() << std::endl;
	std::cout << "Stack1 " << stack1.size() << std::endl;
	std::cout << "Stack2 " << stack2.size() << std::endl;
	std::cout << "-------------------------" << std::endl << std::endl;

	std::cout << "-----------Top-----------" << std::endl;
	std::cout << "Stack1 " << stack1.top() << std::endl;
	std::cout << "Stack2 " << stack2.top() << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << "-----------Push----------" << std::endl;
	std::cout << "Stack1 " << stack1.top() << std::endl;
	std::cout << "Stack2 " << stack2.top() << std::endl << std::endl;
	stack1.push(10);
	stack2.push(100);
	std::cout << "Stack1 " << stack1.top() << std::endl;
	std::cout << "Stack2 " << stack2.top() << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << "-----------Pop-----------" << std::endl;
	std::cout << "Stack1 " << stack1.top() << std::endl;
	std::cout << "Stack2 " << stack2.top() << std::endl << std::endl;
	stack1.pop();
	stack2.pop();
	std::cout << "Stack1 " << stack1.top() << std::endl;
	std::cout << "Stack2 " << stack2.top() << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << "-------Comparaison-------" << std::endl;
	std::cout << "Stack1 " << stack1.top() << std::endl;
	std::cout << "Stack2 " << stack2.top() << std::endl << std::endl;

	std::cout << " == " << (stack == stack1) << (stack1 == stack2) << (stack == stack2)<< std::endl;
	std::cout << " != " << (stack != stack1) << (stack1 != stack2) << (stack != stack2)<< std::endl;
	std::cout << " > " << (stack > stack1) << (stack1 > stack2) << (stack > stack2)<< std::endl;
	std::cout << " < " << (stack < stack1) << (stack1 < stack2) << (stack < stack2)<< std::endl;
	std::cout << " >= " << (stack >= stack1) << (stack1 >= stack2) << (stack >= stack2)<< std::endl;
	std::cout << " <= " << (stack <= stack1) << (stack1 <= stack2) << (stack <= stack2)<< std::endl;
	std::cout << "-------------------------" << std::endl;
	return 0;
}