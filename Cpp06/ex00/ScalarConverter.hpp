#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <sstream>
# include <iomanip>
# include <string>
# include <float.h>

class ScalarConverter
{
	private:
		ScalarConverter( void );
		ScalarConverter( ScalarConverter const &copy );
		~ScalarConverter( void );
		ScalarConverter	&operator=( ScalarConverter const &copy );
	protected:
	public:
		static void			convert( std::string const &Input );
};

#endif