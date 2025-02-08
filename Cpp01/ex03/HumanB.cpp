/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:48:09 by jjhang            #+#    #+#             */
/*   Updated: 2024/09/30 13:31:44 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::HumanB( std::string name, Weapon *weapon )
{
	this->name = name;
	this->weapon = weapon;
}

void	HumanB::attack( void )
{
	std::cout << this->name << " attacked with ";
	if (this->weapon != NULL)
		std::cout << this->weapon->getType() << "!" << std::endl;
	else
		std::cout << "trained fist" << "!" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}