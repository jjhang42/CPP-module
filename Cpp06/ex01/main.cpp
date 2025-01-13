#include "Serializer.hpp"

int	main( void )
{
	Data	ptr1;

	std::cout << "Data *ptr1 addr: " << &ptr1 << std::endl;

	uintptr_t	ptrAddr = Serializer::serialize(&ptr1);
	std::cout << "ptrAddr : " << ptrAddr << std::endl;

	Data	*ptr2 = Serializer::deserialize(ptrAddr);
	std::cout << "Data *ptr2 Addr: " << &(*ptr2) << std::endl;
	return (0);
}