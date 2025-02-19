#include "RPN.hpp"

int	main( int argc, char *argv[] )
{
	std::ofstream	logfile("log.txt");
	if (!logfile)
	{
		std::cerr << "Error: Can not Open LogFile" << std::endl;
		return (1);
	}
	if (argc != 2)
	{
		std::cerr << "Enter one line of parameters for calculation!" << std::endl;
		return (1);
	}
	std::clog.rdbuf(logfile.rdbuf());
	RPN	c;

	try
	{
		c.checkSyntax(argv[1]);
		c.DoRPN(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	std::clog.rdbuf(NULL);
	logfile.close();
	return (0);
}