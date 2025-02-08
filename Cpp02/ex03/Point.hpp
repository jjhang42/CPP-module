/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:16:08 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/24 16:48:09 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

# define Vector Point
class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point( void );
		Point( const float xpos, const float ypos );
		Point( Point const &copy );
		Point &operator=( Point const &copy );
		~Point( void );

		/* setter && getter */
		float	getx( void ) const;
		float	gety( void ) const;
		void	setx( float x );
		void	sety( float y );

		/* vector functions */
		Point	get_vec(Point const &xpos, Point const &ypos);
};

#endif