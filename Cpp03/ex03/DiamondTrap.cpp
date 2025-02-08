/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 05:18:52 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/31 10:25:31 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ClapTrap("DiamondTrap_clap_name"), FragTrap(), ScavTrap()
{
	set_MP(50);
	std::cout << "DiamondTrap " << this->name << " is remade." << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
	this->name = name;
	// set_MP(50);
	std::cout << "DiamondTrap " << this->name << " is remade." << std::endl;
}

DiamondTrap::DiamondTrap( DiamondTrap &copy ) : ClapTrap(copy.get_name())
{
	this->name = copy.name;
	this->set_HP(copy.get_HP());
	this->set_MP(copy.get_MP());
	this->set_AD(copy.get_AD());
	this->set_flag(copy.get_flag());
	this->set_status(copy.get_status());
}

DiamondTrap &DiamondTrap::operator=( DiamondTrap &copy )
{
	if (this == &copy)
		return (*this);
	std::cout << get_name() << " has been copied by operator to DiamondTrap." << std::endl;
	this->set_HP(copy.get_HP());
	this->set_MP(copy.get_MP());
	this->set_AD(copy.get_AD());
	this->set_flag(copy.get_flag());
	return (*this);
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap " << get_name() << " is destroyed." << std::endl;
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "My name is " << this->name << "." << std::endl;
	std::cout << "and Baseclass name is " << get_name() << std::endl;
	std::cout << "HP    :" << get_HP() << std::endl;
	std::cout << "MP    :" << get_MP() << std::endl;
	std::cout << "AD    :" << get_AD() << std::endl;
	std::cout << "FLAG  :" << get_flag() << std::endl;
	std::cout << "STATUS:" << get_status() << std::endl;
}
