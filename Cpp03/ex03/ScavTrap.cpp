/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 05:18:52 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/30 20:59:47 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap( "ScavTrap" )
{
	set_HP( 100 );
	set_MP( 50 );
	set_AD( 20 );
	std::cout << "ClapTrap " << get_name() << " is remade to ScavTrap." << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	set_HP( 100 );
	set_MP( 50 );
	set_AD( 20 );
	std::cout << "ClapTrap " << get_name() << " is remade to ScavTrap." << std::endl;
}

ScavTrap::ScavTrap( ScavTrap &copy ) : ClapTrap(copy.get_name())
{
	*this = copy;
	std::cout << copy.get_name() << " has been copied to ScavTrap." << std::endl;
}

ScavTrap &ScavTrap::operator=( ScavTrap &copy )
{
	if (this == &copy)
		return (*this);
	std::cout << get_name() << " has been copied by operator to ScavTrap." << std::endl;
	this->set_HP(copy.get_HP());
	this->set_MP(copy.get_MP());
	this->set_AD(copy.get_AD());
	this->set_flag(copy.get_flag());
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap " << get_name() << " is destroyed." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	try
	{
		if (get_HP() < 1)
			throw (std::string("ERR"));
		if (get_MP() < 1)
			throw (get_MP());
		std::cout << "ScavTrap "<< \
			get_name() << " attacks " << target << ", causing " << get_AD() << " points of damage!" << std::endl;
			set_MP(get_MP() - 1);
	}
	catch (int num)
	{
		this->Exhaustion();
	}
	catch (std::string err)
	{
		set_HP(0);
		this->Exhaustion();
	}
}

void	ScavTrap::guardGate( void )
{
	try
	{
		if (int expn = (get_HP() == 0))
			throw (std::string("broken"));
		if (int expn = (get_status() == GATEKEEPER))
			throw (expn);
		std::cout << "ScavTrap " << get_name() << " Guards the gate." << std::endl;
		set_status(GATEKEEPER);
	}
	catch(int expn)
	{
		std::cout << "ScavTrap " << get_name() << " is already gatekeeper mode." << std::endl;
	}
	catch(std::string err)
	{
		std::cout << "ScavTrap " << get_name() << " is broken." << std::endl;
	}
}
