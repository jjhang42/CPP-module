#include "ScalarConverter.hpp"

void	testcases( std::string input )
{
	std::cout << "case: " << input << std::endl;
	ScalarConverter::convert( input );
	std::cout << std::endl;
}

int	main(void)
{
	// std::clog.rdbuf(NULL);
	/* tesecases of Subject cpp Module 06 */
	testcases("0");
	testcases("nan");
	testcases("42.0f");
	std::cout << std::endl;

	// /* -inff, +inff, nanf */
	testcases("-inff");
	testcases("+inff");
	testcases("nanf");
	std::cout << std::endl;

	// /* -inf, +inf, nan */
	testcases("-inf");
	testcases("+inf");
	testcases("nan");
	std::cout << std::endl;

	testcases("214748364.7");
	testcases("-0");
	testcases("-3.141592");
	return (0);
}