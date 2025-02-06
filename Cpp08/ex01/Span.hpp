#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <stdexcept>
# include <algorithm>

class Span
{
	private:
		std::vector<int> vector;
		unsigned int	size;
		Span( void );
		class NotEnoughArguments : public std::exception
		{
			public:
				const char *what() const throw();
		};
	protected:
	public:
		/* O.C.C.F */
		Span( Span const &copy );
		Span	&operator=( Span const &copy );
		~Span( void );

		Span( unsigned int N );
		void	addNumber( int number );
		size_t	shortestSpan( void );
		size_t	longestSpan( void );
		void	RandomInput( unsigned int N );
		void	ShowStatus( void );
		template <typename IT>
		void	addNumber( IT begin, IT end )
		{
			if (std::distance(begin, end) > static_cast<int>(size - vector.size()))
				throw( std::out_of_range("Not enough space!"));
			vector.insert(vector.end(), begin, end);
		};
};

#endif