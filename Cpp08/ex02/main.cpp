#include "MutantStack.hpp"

int	main( void )
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::stack<int>	*leaks = new MutantStack<int>();
	leaks->push(5);
	leaks->push(5);
	leaks->push(5);
	leaks->push(5);
	leaks->push(5);
	leaks->push(5);
	leaks->push(5);
	delete leaks;
	return 0;
}


/* It's case of leaks what if you're using polymorphism and Inher. */
// int	main( void )
// {
// 	std::stack *new_stack = new MutantStack(1);
// 	delete new_stack;
// 	return (0);
// }