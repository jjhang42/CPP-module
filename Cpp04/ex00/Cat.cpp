/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:17:48 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/31 23:27:20 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void )
{
	this->type = "Cat";
	std::cout << "Yay! A cat was born!" << std::endl;
}

Cat::Cat( Cat const &copy )
{
	std::cout << "The cat is copied twice!" << std::endl;
	this->type = copy.type;
}

Cat::~Cat( void )
{
	std::cout << "Unfortunately, the cat is in eternal sleep." << std::endl;
}

Cat	&Cat::operator=( Cat const &copy )
{
	if (this == &copy)
	{
		std::cout << "This is the same cat." << std::endl;
		return (*this);
	}
	std::cout << "Hurray! Double the number of copies of the cat." << std::endl;
	this->type = copy.type;
	return (*this);
}

void	Cat::makeSound( void ) const
{
	std::cout << "====================================" << std::endl;
	std::cout << "{\\______/}" << std::endl;
	std::cout << "(⸝⸝> ̫ <⸝⸝)" << std::endl;
	std::cout << "/  ^  ^  \\" << std::endl;
	std::cout << "Meow (the cutest sound in the world)" << std::endl;
	std::cout << "====================================" << std::endl;

}