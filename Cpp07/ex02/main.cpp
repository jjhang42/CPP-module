#include <iostream>
#include "Array.hpp"

#define MAX_VAL 5
# define DEBUG 0
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	if (DEBUG)
		numbers.ShowInfo();
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	if (DEBUG)
		numbers.ShowInfo();
	//SCOPE
	{
		Array<int> tmp = numbers;
		if (DEBUG)
			tmp.ShowInfo();
		Array<int> test(tmp);
		if (DEBUG)
			test.ShowInfo();
	}
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Index is -2: ";
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Index is MAX + 1: ";
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;

	/* const case: */
	Array<char> const num;
	num.ShowInfo();
	Array<char> const ch_(num);
	std::cout << static_cast<int>(ch_[0]) << std::endl;
	return 0;
}