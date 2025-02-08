/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:47:10 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/21 04:03:10 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cctype>

class Fixed
{
	private:
		int					val;
		static const int	bit = 8;
	public:
		/* Orthodox Canonical Form */
		Fixed( void );
		Fixed( int const num );
		Fixed( float const num );
		Fixed( Fixed const &copy );
		~Fixed( void );

		/* overload */
		Fixed	&operator=( Fixed const &ref );

		/* setter && getter */
		int		getRawBits( void ) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

// std::ostream	&operator<<(std::ostream &out, Fixed &ref );
std::ostream	&operator<<(std::ostream &out, Fixed const &ref );

#endif