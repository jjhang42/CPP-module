/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:26:03 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/31 23:15:04 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void )
{
	this->type = "Dog";
	std::cout << "Dog class constructor was called." << std::endl;
}

Dog::Dog( Dog const &copy )
{
	std::cout << "Dog class copy constructor was called." << std::endl;
	this->type = copy.type;
}

Dog::~Dog( void )
{
	std::cout << "Dog death." << std::endl;
}

Dog	&Dog::operator=( Dog const &copy )
{
	if (this == &copy)
	{
		std::cout << "Dog and copy are the same." << std::endl;
		return (*this);
	}
	std::cout << "copy assignment of dog class was called" << std::endl;
	this->type = copy.type;
	return (*this);
}

void	Dog::makeSound( void ) const
{
	std::cout << "dog howling" << std::endl;
}