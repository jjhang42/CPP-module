/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:54:27 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/01 11:19:40 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
	this->type = "Cat";
	std::cout << "Yay! A cat was born!" << std::endl;
}

WrongCat::WrongCat( WrongCat const &copy )
{
	std::cout << "The cat is copied twice!" << std::endl;
	this->type = copy.type;
}

WrongCat::~WrongCat( void )
{
	std::cout << "Unfortunately, the cat is in eternal sleep." << std::endl;
}

WrongCat	&WrongCat::operator=( WrongCat const &copy )
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

void	WrongCat::makeSound( void ) const
{
	std::cout << "====================================" << std::endl;
	std::cout << "{\\______/}" << std::endl;
	std::cout << "(⸝⸝> ̫ <⸝⸝)" << std::endl;
	std::cout << "/  ^  ^  \\" << std::endl;
	std::cout << "Meow (the cutest sound in the world)" << std::endl;
	std::cout << "====================================" << std::endl;

}