#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
		T		*arr;
		size_t	size;
	protected:
	public:
		Array( void );
		Array( unsigned int n );
		Array( Array const &copy );
		Array &operator=( Array const &copy );
		~Array( void );

		/* Array subscript operator */
		T		&operator[](std::size_t idx);
		T const &operator[](std::size_t	idx) const;
		void	ShowInfo( void ) const;
};

#include "Array.tpp"

#endif