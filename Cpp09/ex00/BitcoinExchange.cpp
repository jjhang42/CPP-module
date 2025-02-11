#include "BitcoinExchange.hpp"

/* OCCF */
BitcoinExchange::BitcoinExchange( void )
{

}

BitcoinExchange::BitcoinExchange( BitcoinExchange const &copy )
{
	m = copy.m;
}

BitcoinExchange	&BitcoinExchange::operator=( BitcoinExchange const &copy )
{
	if (this != &copy)
	{
		this->m = copy.m;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange( void )
{

}

/* Exceptions */
const char	*BitcoinExchange::OutOfRange::what( void ) const throw()
{
	return ("Out Of Range");
}

const char	*BitcoinExchange::IsInvalidFile::what( void ) const throw()
{
	return ("Invalid File Format");
}

const char	*BitcoinExchange::IsInvalidDate::what( void ) const throw()
{
	return ("Invalid Date Format");
}

bool	BitcoinExchange::IsValidDate( std::string &str )
{
	bool	result = false;
	return (result);
}

bool	BitcoinExchange::IsValidRange( double value )
{

}