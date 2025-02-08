/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 06:07:17 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/04 15:56:46 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : type("empty slot")
{
	if (DEBUG == true)
		std::cout << "material constructor" << std::endl;
}

AMateria::AMateria( AMateria const &copy ) : type(copy.type)
{
	if (DEBUG == true)
		std::cout << "material copy constructor" << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
	if (DEBUG == true)
		std::cout << "material constructor" << std::endl;
}

AMateria::~AMateria( void )
{
	if (DEBUG == true)
		std::cout << "material destructor" << std::endl;
}

AMateria &AMateria::operator=( AMateria const &copy )
{
	if (DEBUG == true)
		std::cout << "material copy asign" << std::endl;
	if (this == &copy)
		return (*this);
	this->type = copy.type;
	return (*this);
}

std::string const & AMateria::getType( void ) const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Use the item on the " << target.getName() << "." << std::endl;
}
