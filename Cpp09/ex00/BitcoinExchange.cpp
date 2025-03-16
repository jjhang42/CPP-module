#include "BitcoinExchange.hpp"

/* OCCF */
BitcoinExchange::BitcoinExchange( void )
{

}

BitcoinExchange::BitcoinExchange( BitcoinExchange const &copy )
{
	data = copy.data;
}

BitcoinExchange	&BitcoinExchange::operator=( BitcoinExchange const &copy )
{
	if (this != &copy)
	{
		this->data = copy.data;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange( void )
{

}

static void	mvptr( char **endptr, char chr )
{

	if (**endptr == chr)
		(*endptr)++;
}

static int	getDate(char **endptr)
{
	/* date */
	int		date = std::strtol(*endptr, endptr, 10) * 10000;
	mvptr(endptr, '-');
	date += (std::strtol(*endptr, endptr, 10) * 100);
	mvptr(endptr, '-');
	date += std::strtol(*endptr, endptr, 10);
	return (date);
}

void	BitcoinExchange::setData( std::string const &line )
{
	char	*endptr = const_cast<char *>(line.c_str());
	int year = getDate(&endptr);
	mvptr(&endptr, ',');
	/* value */
	ssize_t	value = std::strtol(endptr, &endptr, 10);
	mvptr(&endptr, '.');
	for (int i = 0; i < 2 ; i++)
	{
		// you must fixed
		if (endptr[i] != '\0' && '0' <= endptr[i] && endptr[i] <= '9')
			value = value * 10 + (endptr[i] - '0');
		else
			value = value * 10;
	}
	data.insert(std::make_pair(year, value));
}

static int	getYear( int date )
{
	return (date / 10000);
}

static int	getMonth( int date )
{
	return ((date % 10000) / 100);
}

static int	getDay( int date )
{
	return ( date % 100);
}

static std::string	printDate( int date )
{
	std::ostringstream	oss;
	int	year = getYear(date);
	int	month = getMonth(date);
	int	day = getDay(date);
	oss << year << "-";
	if (month < 10)
		oss << "0";
	oss << month << "-";
	if (day < 10)
		oss << "0";
	oss << day;
	return (oss.str());
}

static bool IsInvalidDate( int date )
{
	char daymax[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (getMonth(date) == 2 && getYear(date) % 4 == 0 && !(getYear(date) % 100 == 0 && getYear(date) % 400 != 0))
	{
		daymax[2] = 29;
	}
	if (daymax[getMonth(date)] < getDay(date))
		return (false);
	if (getYear(date) < 2009 || (getYear(date) <= 2009 && getMonth(date) == 1 && getDay(date) == 1))
		return (false);
	return (true);
}

double	BitcoinExchange::getMarketValue( double num, int date )
{
	std::map<int, ssize_t>::iterator it = data.lower_bound(date);
	if (it == data.end() || it->first > date)
	{
		if (it == data.begin())
			return (0);
		--it;
	}
	double	temp = (it->second * 0.01);
	num = 0;
	return (std::round(temp * 100) / 100);
}

void	BitcoinExchange::printAnswer( std::string const &line )
{
	char	*endptr = const_cast<char *>(line.c_str());
	/* date */
	int		date = getDate(&endptr);
	while (*endptr != '\0' && (*endptr == ' ' || (9 <= *endptr && *endptr <= 13)))
	{
		endptr++;
	}
	mvptr(&endptr, '|');
	while (*endptr != '\0' && (*endptr == ' ' || (9 <= *endptr && *endptr <= 13)))
	{
		endptr++;
	}
	double	num = std::strtod(endptr, &endptr);
	if (num < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return ;
	}
	else if (!IsInvalidDate(date))
	{
		std::cerr << "Error: bad input => " << printDate(date) << std::endl;
		return ;
	}
	else if (num > INT_MAX)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return ;
	}
	std::cout << printDate(date) << " => " << num << " = " << num * getMarketValue(num, date) << std::endl;
}

void	BitcoinExchange::InfoMap( void )
{
	std::cout << "===<Info Map>===" << std::endl;
	for (std::map<int, ssize_t>::iterator it = data.begin(); it != data.end() ; ++it)
	{
		std::cout << it->first << " | " << it->second << std::endl;
	}
	std::cout << "================" << std::endl;
}