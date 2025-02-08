/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:46:56 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/24 19:21:13 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
bool bsp( Point const a, Point const b, Point const c, Point const point );

int main( void )
{
	Point const	a(-5, 0);
	Point const	b(5, 0);
	Point const	c(0, 10);

	Point const	point(-10, 0);
	// Point const	point(10, 0);
	// Point const	point(0, 5);
	bool		check;

	check = bsp(a, b, c, point);
	if (check == true)
		std::cout << "[OK]: The point is inside of trianfle" << std::endl;
	else
		std::cout << "[NO]: The point is not inside of trianfle" << std::endl;
	return 0;
}
