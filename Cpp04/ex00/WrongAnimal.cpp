/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:45:33 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/01 10:52:48 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("Animal")
{
	std::cout << "Animal class constructor was called." << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const &copy )
{
	std::cout << "Animal class copy constructor was called." << std::endl;
	this->type = copy.type;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "Animal class destructor was called." << std::endl;
}

WrongAnimal	&WrongAnimal::operator=( WrongAnimal const &copy )
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

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "Animals should not make noise." << std::endl;
}

void	WrongAnimal::setType( std::string type )
{
	this->type = type;
	std::cout << "Animal class has been set." << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	std::cout << "Animal class has been get." << std::endl;
	return ( this->type );
}
