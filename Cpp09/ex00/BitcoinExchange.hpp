#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHARGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <exception>

class BitcoinExchange
{
private:
	/* Exceptions */
	class OutOfRange : public std::exception
	{
		const char	*what( void ) const throw();
	};
	class IsInvalidFile : public std::exception
	{
		const char	*what( void ) const throw();
	};
	class IsInvalidDate : public std::exception
	{
		const char	*what( void ) const throw();
	};
	/* data */
	std::map<std::string, std::string>	m;
public:
	/* OCCF */
	BitcoinExchange( void );
	BitcoinExchange( BitcoinExchange const &copy );
	BitcoinExchange	&operator=( BitcoinExchange const &copy );
	~BitcoinExchange( void );

	/* Is Valid */
	bool	IsValidDate( std::string	&str );
	bool	IsValidRange( double value );
};

#endif