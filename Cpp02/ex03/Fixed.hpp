/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:47:10 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/31 04:41:16 by jjhang           ###   ########.fr       */
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

		/* comparison operator */
		bool	operator<( Fixed const &ref );
		bool	operator>( Fixed const &ref );
		bool	operator>=( Fixed const &ref );
		bool	operator<=( Fixed const &ref );
		bool	operator==( Fixed const &ref );
		bool	operator!=( Fixed const &ref );

		/* arithymetic operator */
		Fixed operator+( Fixed const &ref );
		Fixed operator-( Fixed const &ref );
		Fixed operator*( Fixed const &ref );
		Fixed operator/( Fixed const &ref );

		/* Increment && Decrement */
		Fixed &operator++( void );
		Fixed operator++( int );
		Fixed &operator--( void );
		Fixed operator--( int );
		/* setter && getter */
		int		getRawBits( void ) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
		/* min && max */
		static Fixed	&min(Fixed &f1, Fixed &f2);
		static const Fixed	&min(const Fixed &f1, const Fixed &f2);
		static Fixed	&max(Fixed &f1, Fixed &f2);
		static const Fixed	&max(const Fixed &f1, const Fixed &f2);
};

std::ostream	&operator<<( std::ostream &out, Fixed const &ref );

#endif