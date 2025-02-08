/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:03:28 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/04 16:06:12 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void )
{
	if (DEBUG == true)
		std::cout << "ice constructor" << std::endl;
	this->type = "ice";
}

Ice::Ice( std::string const &type )
{
	if (DEBUG == true)
		std::cout << "ice constructor" << std::endl;
	this->type = type;
}

Ice::Ice( Ice const &copy )
{
	if (DEBUG == true)
		std::cout << "ice constructor" << std::endl;
	this->type = copy.type;
}

Ice::~Ice( void )
{
	if (DEBUG == true)
		std::cout << "ice destrcutor" << std::endl;
}

Ice &Ice::operator=( Ice const &copy )
{
	if (this == &copy)
		return (*this);
	type = copy.type;
	return (*this);
}

Ice *Ice::clone( void ) const
{
	Ice	*res = new Ice("ice");
	return (res);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
