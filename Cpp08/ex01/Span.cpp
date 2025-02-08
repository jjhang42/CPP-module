#include "Span.hpp"

Span::Span( Span const &copy ) : vector(copy.vector), size(copy.size)
{
}

Span	&Span::operator=( Span const &copy )
{
	if (this != &copy)
	{
		size = copy.size;
		vector = copy.vector;
	}
	return (*this);
}

Span::~Span( void )
{

}

Span::Span( unsigned int N ) : size(N)
{
	vector.reserve( N );
	// std::clog << "Size: " << vector.size() << std::endl;
	// std::clog << "Capacity: " << vector.capacity() << std::endl;
}

void	Span::addNumber( int number )
{
	if ( vector.size() > size )
		throw (std::out_of_range("too much arguments"));
	vector.push_back( number );
}

size_t	Span::shortestSpan( void ) // must be using algorithm
{
	if (vector.size() < 2)
		throw (NotEnoughArguments());
	std::vector<int>	temp;
	temp = this->vector;
	std::sort(temp.begin(), temp.end());
	size_t	result = static_cast<size_t>(std::abs(static_cast<int>(static_cast<size_t>(temp[1]) - static_cast<size_t>(temp[0]))));
	for (unsigned long	i = 1; i < temp.size(); i++)
	{
		size_t	diff = static_cast<size_t>(std::abs(temp[1] - temp[0]));
		if (diff < result)
			result = diff;
	}
	return (result);
}

size_t	Span::longestSpan( void ) // must be using algorithm
{
	if (vector.size() < 2)
		throw (NotEnoughArguments());
	std::vector<int>	temp;
	temp = this->vector;
	std::sort(temp.begin(), temp.end());
	return (std::abs(*temp.begin() - *(temp.end() - 1)));
}

const char	*Span::NotEnoughArguments::what( void ) const throw()
{
	return ("Not Enough Arguments");
}

void	Span::RandomInput( unsigned int N )
{
	for (unsigned int i = 0; i < N; i++)
	{
		addNumber((rand() * time(NULL)) % 10000);
	}
}

void	Span::ShowStatus( void )
{
	std::cout << "========================================" << std::endl;
	for (unsigned int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i];
		if (vector.size() != i + 1)
			std::cout << ", ";
		else
			std::cout << std::endl;
	}
	std::cout << "========================================" << std::endl;
}
