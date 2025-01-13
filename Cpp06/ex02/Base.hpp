#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>

# define A_TYPE 0
# define B_TYPE 1
# define C_TYPE 2

class Base
{
	private:
	protected:
	public:
		virtual ~Base( void );
};


Base	*generate( void );
void	identify( Base *p );
void	identify( Base &p );

#endif