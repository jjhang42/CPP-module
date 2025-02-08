#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename F>
void	iter(T const *arr, size_t size, F const f)
{
	for (size_t	i = 0; i < size; ++i)
	{
		f(const_cast<T &>(arr[i]));
	}
}

#endif