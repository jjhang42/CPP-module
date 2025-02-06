#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.ShowStatus();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	Span Lots(100);
	Lots.RandomInput(101);
	Lots.ShowStatus();
	std::cout << Lots.shortestSpan() << std::endl;
	std::cout << Lots.longestSpan() << std::endl;
	try
	{
		Lots.addNumber(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::vector<int>	add;
	add.push_back(3);
	add.push_back(5);
	add.push_back(6);
	add.push_back(7);
	add.push_back(9);
	add.push_back(12);

	Span	s(6);
	s.addNumber(add.begin(), add.end());
	s.ShowStatus();
	std::cout << s.shortestSpan() << std::endl;
	std::cout << s.longestSpan() << std::endl;
	return 0;
}