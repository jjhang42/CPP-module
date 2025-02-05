#include "MutantStack.hpp"

template < typename T, class _Container >
MutantStack<T, _Container>::MutantStack( void ) : std::stack<T, _Container>()
{
}

template < typename T, class _Container >
MutantStack<T, _Container>::MutantStack( MutantStack const &copy ) : std::stack<T, _Container>( copy.c )
{
}

template <typename T, class _Container>
MutantStack<T, _Container>	&MutantStack<T, _Container>::operator=( MutantStack const &copy )
{
	if (this != &copy)
	{
		this->c = copy.c;
	}
	return (*this);
}

template <typename T, class _Container>
MutantStack<T, _Container>::~MutantStack( void )
{
}

// template <typename T, class Container>
// MutantStack<T, Container>::reference	MutantStack<T, Container>::top( void )
// {
// 	return (c.back());
// }

// template <typename T, class Container>
// MutantStack<T, Container>::const_reference	MutantStack<T, Container>::top( void ) const
// {
// 	return (c.back());
// }

// /* Capacity */
// template <typename T, class Container>
// bool	MutantStack<T, Container>::empty( void ) const
// {
// 	return (c.empty());
// }

// template <typename T, class Container>
// MutantStack<T, Container>::size_type	MutantStack<T, Container>::size( void ) const
// {
// 	return (c.size());
// }

// /* modifiers */
// template <typename T, class Container>
// void	MutantStack<T, Container>::push( const value_type& value )
// {
// 	c.push_back( value );
// }

// void			push( value_type&& value ); // since c++ 11

// template <typename T, class Container>
// void	MutantStack<T, Container>::pop( void )
// {
// 	c.pop_back();
// }

template <typename T, class Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin( void )
{
	return (this->c.begin());
}

template <typename T, class Container>
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::begin( void ) const
{
	return (this->c.begin());
}

template <typename T, class Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end( void )
{
	return (this->c.end());
}

template <typename T, class Container>
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::end( void ) const
{
	return (this->c.end());
}

template <typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rbegin( void )
{
	return (this->c.rbegin());
}

template <typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::rbegin( void ) const
{
	return (this->c.rbegin());
}

template <typename T, class Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rend( void )
{
	return (this->c.rend());
}

template <typename T, class Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::rend( void ) const
{
	return (this->c.rend());
}
