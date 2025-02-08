/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:46:56 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/31 06:42:28 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed c(1);
	Fixed d(2);
	std::cout << "cal-------------" << std::endl;
	std::cout << c + d <<std::endl;
	std::cout << "res: 3" << std::endl;
	std::cout << c + d + c + d << std::endl;
	std::cout << "res: 6" << std::endl;
	std::cout << c * d << std::endl;
	std::cout << "res: 2" << std::endl;
	std::cout << c * d * d * d * d << std::endl;
	std::cout << "res: 16" << std::endl;
	std::cout << c - d << std::endl;
	std::cout << "res: -1" << std::endl;
	std::cout << c - d - d - d << std::endl;
	std::cout << "res: -5" << std::endl;
	std::cout << c / d << std::endl;
	std::cout << "res: 0.5" << std::endl;
	return (0);
}
