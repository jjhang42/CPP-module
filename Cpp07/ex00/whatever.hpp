#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void	swap( T const &a, T const &b )
{
	T	temp;

	temp = const_cast<T &>(b);
	const_cast<T &>(b) = const_cast<T &>(a);
	const_cast<T &>(a) = temp;
}

template <typename T>
T	&min( T const &a, T const &b )
{
	if (a < b)
		return (const_cast<T &>(a));
	return (const_cast<T &>(b));
}

template <typename T>
T	&max( T const &a, T const &b )
{
	if (a > b)
		return (const_cast<T &>(a));
	return (const_cast<T &>(b));
}

#endif