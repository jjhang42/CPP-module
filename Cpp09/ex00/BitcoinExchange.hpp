#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>
# include <fstream>
# include <string>
# include <cmath>
# include <map>

class BitcoinExchange
{
	private:
		/* data */
		std::map<int, ssize_t>		data;
		double	getMarketValue( double num, int date );
	public:
		/* OCCF */
		BitcoinExchange( void );
		BitcoinExchange( BitcoinExchange const &copy );
		BitcoinExchange	&operator=( BitcoinExchange const &copy );
		~BitcoinExchange( void );


		/* Is Valid */

		/* getter && setter */
		void	setData( std::string const &line );
		void	printAnswer( std::string const &line );
		void	InfoMap( void );
};

#endif