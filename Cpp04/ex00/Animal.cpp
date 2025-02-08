/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:05:09 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/31 14:53:23 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : type("Animal")
{
	std::cout << "Animal class constructor was called." << std::endl;
}

Animal::Animal( Animal const &copy )
{
	std::cout << "Animal class copy constructor was called." << std::endl;
	this->type = copy.type;
}

Animal::~Animal( void )
{
	std::cout << "Animal class destructor was called." << std::endl;
}

Animal	&Animal::operator=( Animal const &copy )
{
	if (this == &copy)
	{
		std::cout << "The assignment and target are the same." << std::endl;
		return (*this);
	}
	std::cout << "copy assignment of animal class was called" << std::endl;
	this->type = copy.type;
	return (*this);
}

void	Animal::makeSound( void ) const
{
	std::cout << "Animals should not make noise." << std::endl;
}

void	Animal::setType( std::string type )
{
	this->type = type;
	std::cout << "Animal class has been set." << std::endl;
}

std::string	Animal::getType( void ) const
{
	std::cout << "Animal class has been get." << std::endl;
	return ( this->type );
}
