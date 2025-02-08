/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:15:57 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/23 17:05:34 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : x(0), y(0)
{
}

Point::Point( const float xpos, const float ypos ) : x(xpos), y(ypos)
{
}

Point::Point( Point const &copy )
{
	*this = copy;
}

Point &Point::operator=( Point const &copy )
{
	const_cast<Fixed&>(this->x) = copy.x;
	const_cast<Fixed&>(this->y) = copy.y;
	return (*this);
}

Point::~Point( void )
{
}

float	Point::getx( void ) const
{
	return (this->x.toFloat());
}

float	Point::gety( void ) const
{
	return (this->y.toFloat());
}

void	Point::setx( float x )
{
	Fixed const pos(x);
	const_cast<Fixed&>(this->x) = pos;
}

void	Point::sety( float y )
{
	Fixed const pos(y);
	const_cast<Fixed&>(this->y) = pos;
}

Point	Point::get_vec(Point const &xpos, Point const &ypos)
{
	Point const pos(ypos.getx() - xpos.getx(), ypos.gety() - xpos.gety());
	return (pos);
}
