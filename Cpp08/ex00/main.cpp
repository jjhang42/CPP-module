#include "easyfind.hpp"
#include <vector>

template <typename T>
void	routine_easyfind(T &vec,  int input )
{
	std::cout << "============" << std::endl;
	std::cout << "easyFind: " << input << std::endl;
	try
	{
		/* code */
		typename T::iterator	res;
		res = easyfind(vec, input);
		std::cout << "found: " << *res << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main( void )
{
	{
		/* int */
		std::vector<int>	vec;
		std::cout << "vec = {1, 2, 3, 4}" << std::endl;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);

		routine_easyfind( vec, 4 );
		routine_easyfind( vec, 5 );
	}

	return (0);
}