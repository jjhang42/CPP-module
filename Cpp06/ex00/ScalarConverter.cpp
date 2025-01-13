#include "ScalarConverter.hpp"

void	ScalarConverter::convert( std::string const &Input )
{
	double	d = std::strtod(Input.c_str(), NULL);

	std::cout << "?:" << d << std::endl;
	/* char dataset */
	char c = static_cast<char>(d);

	std::cout << "char: ";
	if (!(std::numeric_limits<char>::min() <= d && d < std::numeric_limits<char>::max()))
		std::cout << "impossible";
	else if (!std::isprint(c))
		std::cout << "Non displayable";
	else
		std::cout << c;
	std::cout << std::endl;
	/* int dataset */
	int	i = static_cast<int>(d);

	std::cout << "int: ";
	if (!(std::numeric_limits<int>::min() <= d && d <= std::numeric_limits<int>::max()))
		std::cout << "impossible";
	else
		std::cout << i;
	std::cout<< std::endl;

	/* float dataset */
	float	f = static_cast<float>(d);

	std::cout << "float: " << f;
	if ( d - static_cast<int>(d) == 0 )
		std::cout << ".0";
	std::cout << "f" << std::endl;

	/* double dataset */
	std::cout << "double: " << d;
	if ( d - static_cast<int>(d) == 0 )
		std::cout << ".0";
	std::cout << std::endl;
}
