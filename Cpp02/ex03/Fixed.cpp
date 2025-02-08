/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 02:25:07 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/31 06:41:08 by jjhang           ###   ########.fr       */
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

std::ostream	&operator<<( std::ostream &out, Fixed const &ref )
{
	out << ref.toFloat();
	return (out);
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->val);
}

void	Fixed::setRawBits(int const raw )
{
	this->val = raw;
}

float	Fixed::toFloat( void ) const
{
	float	num = (static_cast<float>(val) / (1 << bit));
	return (num);
}

int		Fixed::toInt( void ) const
{
	return (val >> bit);
}

bool	Fixed::operator<( Fixed const &ref )
{
	if (this->val < ref.val)
		return (true);
	return (false);
}

bool	Fixed::operator>( Fixed const &ref )
{
	if (this->val > ref.val)
		return (true);
	return (false);
}

bool	Fixed::operator>=( Fixed const &ref )
{
	if (this->val >= ref.val)
		return (true);
	return (false);
}

bool	Fixed::operator<=( Fixed const &ref )
{
	if (this->val <= ref.val)
		return (true);
	return (false);
}

bool	Fixed::operator==( Fixed const &ref )
{
	if (this->val == ref.val)
		return (true);
	return (false);
}

bool	Fixed::operator!=( Fixed const &ref )
{
	if (this->toFloat() != ref.toFloat())
		return (true);
	return (false);
}

Fixed	Fixed::operator+( Fixed const &ref )
{
	Fixed	res;

	res.val = this->val + ref.val;
	return (res);
}

Fixed	Fixed::operator-( Fixed const &ref )
{
	Fixed	res;

	res.val = this->val - ref.val;
	return (res);
}

Fixed	Fixed::operator*( Fixed const &ref )
{
	Fixed	res;

	res.val = (this->val * ref.val) / (1 << this->bit);
	return (res);
}

Fixed	Fixed::operator/( Fixed const &ref )
{
	Fixed	res;

	res.val = (this->val * (1 << this->bit)) / ref.val;
	return (res);
}

Fixed	&Fixed::operator++( void )
{
	this->val += 1;
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed	op(*this);

	this->val += 1;
	return (op);
}

Fixed	&Fixed::operator--( void )
{
	this->val -= 1;
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed	op(*this);

	this->val -= 1;
	return (op);
}

Fixed	&Fixed::min( Fixed &f1, Fixed &f2 )
{
	if (f1.val < f2.val)
		return (f1);
	return (f2);
}

const Fixed	&Fixed::min( const Fixed &f1, const Fixed &f2 )
{
	if (f1.val < f2.val)
		return (f1);
	return (f2);
}

Fixed	&Fixed::max( Fixed &f1, Fixed &f2 )
{
	if (f1.val > f2.val)
		return (f1);
	return (f2);
}

const Fixed	&Fixed::max( const Fixed &f1, const Fixed &f2 )
{
	if (f1.val > f2.val)
		return (f1);
	return (f2);
}

