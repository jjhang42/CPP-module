#include "Data.hpp"

Data::Data( void )
{
	value = 0;
}

Data::Data( Data const &Data )
{
	this->value = Data.value;
}

Data::~Data( void )
{

}

Data &Data::operator=( Data const &Data )
{
	this->value = Data.value;
	return (*this);
}

void	Data::setValue( int val )
{
	this->value = val;
}

int	Data::getValue( void ) const
{
	return ( value );
}