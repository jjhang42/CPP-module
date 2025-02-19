#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <exception>
# include <fstream>

# define FALSE 0
# define ADD 1
# define MINUS 2
# define TIMES 3
# define DIV 4

class RPN
{
	private:
		std::stack<int>	c;
		int	(*functionpointer[5])(int, int);
		RPN( const RPN &copy );
		RPN	&operator=( const RPN &copy );
		class TokenError : public std::exception
		{
			const char	*what( void ) const throw();
		};
		class SyntaxError : public std::exception
		{
			const char	*what( void ) const throw();
		};
		class SyntaxFormatError : public std::exception
		{
			const char	*what( void ) const throw();
		};
		void	Tureout( int idx );
	protected:
	public:
		RPN( void );
		~RPN( void );
		void	checkSyntax( std::string const &line );
		void	DoRPN( std::string const &line );
};

int	Add(int a, int b);
int	Minus(int a, int b);
int	Times(int a, int b);
int	Div(int a, int b);

#endif