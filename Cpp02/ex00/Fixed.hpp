/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:47:10 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/09 06:47:41 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cctype>

class Fixed
{
	private:
		int	fixNumber;
		static const int	bit = 8;
	public:
		/* Orthodox Canonical Form */
		Fixed( void );
		Fixed( const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		~Fixed( void );

		/* setter && getter */
		int		getRawBits( void ) const;
		void	setRawBits(int const raw);
};

#endif