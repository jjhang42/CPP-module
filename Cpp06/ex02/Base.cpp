#include "Base.hpp"
/* empty file */

Base::~Base( void )
{

}

# include "A.cpp"
# include "B.cpp"
# include "C.cpp"

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

static void	dynamicCastRef( Base &p, int type, std::string const &str )
{
	try
	{
		if (type == A_TYPE)
			(void)dynamic_cast<A &>(p);
		else if (type == B_TYPE)
			(void)dynamic_cast<B &>(p);
		else if (type == C_TYPE)
			(void)dynamic_cast<C &>(p);
		std::cout << str << std::endl;
	}
	catch(const std::exception& e)
	{
	}
}

void	identify( Base &p )
{
	dynamicCastRef(p, A_TYPE, "A");
	dynamicCastRef(p, B_TYPE, "B");
	dynamicCastRef(p, C_TYPE, "C");
}