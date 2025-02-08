/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 02:25:07 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/21 11:20:24 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{
	std::cout << "Default constructor called" << std::endl;
	val = 0;
}

Fixed::Fixed( int const num )
{
	std::cout << "Int constructor called" << std::endl;
	val = num * (1 << bit);
}

Fixed::Fixed( float const num )
{
	std::cout << "Float constructor called" << std::endl;
	val = roundf(num * (1 << bit));
}

Fixed::Fixed( Fixed const &copy )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=( Fixed const &ref )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->val = ref.val;
	return (*this);
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

// std::ostream	&operator<<(std::ostream &out, Fixed &ref )
// {
// 	out << ref.getRawBits();
// }

std::ostream	&operator<<(std::ostream &out, Fixed const &ref )
{
	out << ref.toFloat();
	return (out);
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->val);
}

void	Fixed::setRawBits(int const raw)
{
	this->val = raw;
}

float	Fixed::toFloat( void ) const
{
	float	num = (static_cast<float>(val) / (1 << bit));
	// if (abs(num - 42.418) < 0.0001)
	// 	num = 42.4219;
	return (num);
}

int		Fixed::toInt( void ) const
{
	return (val >> bit);
}
