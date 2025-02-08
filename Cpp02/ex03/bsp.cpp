/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:03:11 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/24 18:48:05 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	check_point( Point const &a, Point const &b, Point const &point)
{
	int result = (b.getx() - a.getx()) * (point.gety() - a.gety()) - \
				(b.gety() - a.gety()) * (point.getx() - a.getx());
	return (result);
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	int	sign1 = check_point(a, b, point);
	int	sign2 = check_point(b, c, point);
	int	sign3 = check_point(c, a, point);

	std::cout << "sign1: " << sign1 << std::endl;
	std::cout << "sign2: " << sign2 << std::endl;
	std::cout << "sign3: " << sign3 << std::endl;
	if (0 < sign1 && 0 < sign2 && 0 < sign3)
		return (true);
	if (0 > sign1 && 0 > sign2 && 0 > sign3)
		return (true);
	return (false);
}
