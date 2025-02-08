#include "iter.hpp"
# include <vector>
# include <list>
# include <map>

template <typename T>
void	PrintArr( T const &a )
{
	std::cout << a << std::endl;
}

int	main( void )
{
	std::cout << "print int arr: " << std::endl;
	int intArr[] = {4, 3, 2, 5, 1};
	iter(intArr, 5, PrintArr<int>);

	std::cout << "print double arr: " << std::endl;
	double	doubleArr[] = {0.1, 1.2, 2.0, 2.2, 3.3, 4.71237, 6.32, 21};
	iter(doubleArr, 7, PrintArr<double>);

	std::cout << "print char arr: " << std::endl;
	char charArr[] = {'T', 'E', 'M', 'P'};
	iter(charArr, 4, PrintArr<char>);

	std::cout << "print string arr: " << std::endl;
	std::string strArr[] = {"hello", "world"};
	iter(strArr, 2, PrintArr<std::string>);

	std::cout << "print int const arr: " << std::endl;
	int const CintArr[] = {4, 3, 2, 5, 1};
	iter(CintArr, 5, PrintArr<int const>);
	return (0);
}