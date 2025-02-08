#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array( void ) : size(1)
{
	arr = new T[1];
	std::memset(arr, 0, 1 * sizeof(T));
	std::clog << "constuctor called" << std::endl;
}

template <typename T>
Array<T>::Array( unsigned int n ) : size(n)
{
	arr = new T [ this->size ];
	std::memset(arr, 0, size * sizeof(T));
	std::clog << "constuctor with parameters called" << std::endl;
}

template <typename T>
Array<T>::Array( Array const &copy ) : size(copy.size)
{
	arr = new T [ this->size ];
	std::memcpy(this->arr, copy.arr, sizeof(T) * copy.size);
	std::clog << "copy constuctor called" << std::endl;
}

template <typename T>
Array<T> &Array<T>::operator=( Array const &copy )
{
	if (this == &copy)
		return (*this);
	delete [] arr;
	this->size = copy.size;
	arr = new T[ copy.size ];
	std::memcpy(this->arr, copy.arr, sizeof(T) * copy.size);
	std::clog << "assignment constuctor called" << std::endl;
	return (*this);
}

template <typename T>
Array<T>::~Array( void )
{
	delete [] arr;
	std::clog << "destructor called" << std::endl;
}

template <typename T>
T		&Array<T>::operator[](std::size_t idx)
{
	if (idx >= size)
		throw (std::out_of_range("Index out of range"));
	return (arr[idx]);
}

template <typename T>
T const	&Array<T>::operator[](std::size_t idx) const
{
	if (idx >= size)
		throw (std::out_of_range("Index out of range"));
	return (arr[idx]);
}

template <typename T>
void	Array<T>::ShowInfo( void ) const
{
	std::clog << "===============" << std::endl;
	std::clog << "type size: " << sizeof(T) << std::endl;
	std::clog << "arr size: " << size << std::endl;
	std::clog << "show the arr info" << std::endl;
	for (size_t i = 0; i < this->size; i++)
	{
		std::clog << arr[i];
		if (i + 1 < this->size)
			std::clog << ",";
		else
			std::clog << std::endl;
	}
	std::clog << "===============" << std::endl;
}

#endif