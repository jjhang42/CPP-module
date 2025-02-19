#include "RPN.hpp"

int	Add(int a, int b)
{
	return (a + b);
}

int	Minus(int a, int b)
{
	return (a - b);
}

int	Times(int a, int b)
{
	return (a * b);
}

int	Div(int a, int b)
{
	return (a / b);
}

RPN::RPN( void )
{
	functionpointer[FALSE] = NULL;
	functionpointer[ADD] = &Add;
	functionpointer[MINUS] = &Minus;
	functionpointer[TIMES] = &Times;
	functionpointer[DIV] = &Div;
}

RPN::~RPN( void )
{
}

const char	*RPN::TokenError::what( void ) const throw ()
{
	return ("Syntax Error: Supports only basic arithmetic operations(+,-,*,/)");
}

const char	*RPN::SyntaxError::what( void ) const throw ()
{
	return ("Syntax Error: Invalid Parameter");
}

const char	*RPN::SyntaxFormatError::what( void ) const throw ()
{
	return ("Syntax Format Error: Spaces and tokens should alternate");
}

static int	IsToken( char c )
{
	if (c == '+')
		return (ADD);
	if (c == '-')
		return (MINUS);
	if (c == '*')
		return (TIMES);
	if (c == '/')
		return (DIV);
	return (FALSE);
}

void	RPN::checkSyntax( std::string const &line )
{
	char	*ptr = const_cast<char *>(line.c_str());
	int		i;

	i = 0;
	if (*ptr != '\0' && *ptr == ' ')
	{
		ptr++;
	}
	while (ptr[i] != '\0')
	{
		if (i % 2 == 0 && ptr[i] == ' ')
			throw (SyntaxFormatError());
		else if (i % 2 == 1 && (std::isdigit(ptr[i]) || IsToken(ptr[i])))
			throw (SyntaxFormatError());
		i++;
	}
}

void	RPN::Tureout( int idx )
{
	int	a;
	int	b;

	if (c.empty())
		throw (SyntaxError());
	b = c.top();
	c.pop();
	if (c.empty())
		throw (SyntaxError());
	a = c.top();
	c.pop();
	c.push((functionpointer[idx])(a, b));
	std::clog << "cal: " << a << " [" << idx << "] " << b << " = " << c.top() << std::endl;
}

void	RPN::DoRPN( std::string const &line )
{
	char	*ptr = const_cast<char *>(line.c_str());
	int		result = 0;

	if (*ptr != '\0' && *ptr == ' ')
		ptr++;
	while (*ptr != '\0')
	{
		if (*ptr == ' ')
		{
			ptr++;
		}
		else if ('0' <= *ptr && *ptr <= '9')
		{
			c.push(std::strtol(ptr, &ptr, 10));
		}
		else if (IsToken(*ptr) != FALSE)
		{
			Tureout( IsToken(*ptr) );
			ptr++;
		}
		else
			throw (TokenError());
	}
	if (!c.empty())
	{
		result = c.top();
		c.pop();
	}
	if (!c.empty())
		throw(SyntaxError());
	std::clog << "Answer: " << result << std::endl;
	std::cout << result << std::endl;
}
