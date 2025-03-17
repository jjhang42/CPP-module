#include "BitcoinExchange.hpp"

bool	IsExtension( std::string const &filename, std::string const &extension )
{
	if (filename.size() <= extension.size())
	{
		std::cerr << "This is not valid file extension!" << std::endl;
		return (false);
	}
	if (filename.substr(filename.size() - extension.size()) != extension)
	{
		std::cerr << "This is not valid file extension!" << std::endl;
		return (false);
	}
	return (true);
}

int	checkParameter(int argc)
{
	if (argc != 2)
	{
		std::cerr << "This program must need a parameter What It's the filename." << std::endl;
		return (1);
	}
	return (0);
}

int	main( int argc, char *argv[] )
{
	BitcoinExchange	bit;

	if (checkParameter(argc))
		return (ERROR);
	if (IsExtension( argv[1], ".txt") == false)
		return (ERROR);
	std::ifstream	file("data.csv");
	if (!file)
	{
		std::cerr << "Error: file open failed!" << std::endl;
		return (ERROR);
	}
	std::string	line;
	while (std::getline(file, line))
	{
		bit.setData(line);
	}
	file.close();
	std::ifstream	input(argv[1]);
	if (!input)
	{
		std::cerr << "Error: file open failed!" << std::endl;
		return (ERROR);
	}
	std::getline(input, line);
	while (std::getline(input, line))
	{
		bit.printAnswer(line);
	}
	input.close();
	return (0);
}