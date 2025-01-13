#ifndef	SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>

# include "Data.hpp"

class Serializer
{
	private:
		Serializer( void );
		Serializer( Serializer const &copy );
		Serializer	&operator=( Serializer const &copy );
		~Serializer( void );
	protected:
	public:
		static uintptr_t	serialize ( Data *ptr );
		static Data		*deserialize( uintptr_t raw );
};

#endif