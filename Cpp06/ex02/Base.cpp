#include "Base.hpp"
/* empty file */
# include "A.cpp"
# include "B.cpp"
# include "C.cpp"

Base::~Base( void )
{

}

Base	*generate( void )
{
	int	type = std::time(NULL) % 3;
	if (type == A_TYPE)
		return (static_cast<Base *>(new A));
	if (type == B_TYPE)
		return (static_cast<Base *>(new B));
	if (type == C_TYPE)
		return (static_cast<Base *>(new C));
	return (NULL);
}

void	identify( Base *p )
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
}

void	identify( Base &p )
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "failure" << std::endl;
			}
			
		}
	}
}