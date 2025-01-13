#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main( void )
{
	Base	*random = generate();

	std::cout << "pointer: ";
	identify(random);
	std::cout << "reference: ";
	identify(*random);
	return (0);
};