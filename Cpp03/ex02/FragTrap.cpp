/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 05:18:52 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/30 21:18:08 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap( "FragTrap" )
{
	set_HP( 100 );
	set_MP( 100 );
	set_AD( 30 );
	std::cout << "ClapTrap " << get_name() << " is remade to FragTrap." << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
	set_HP( 100 );
	set_MP( 100 );
	set_AD( 30 );
	std::cout << "ClapTrap " << get_name() << " is remade to FragTrap." << std::endl;
}

FragTrap::FragTrap( FragTrap &copy ) : ClapTrap(copy.get_name())
{
	*this = copy;
	std::cout << copy.get_name() << " has been copied to FragTrap." << std::endl;
}

FragTrap &FragTrap::operator=( FragTrap &copy )
{
	if (this == &copy)
		return (*this);
	std::cout << get_name() << " has been copied by operator to FragTrap." << std::endl;
	this->set_HP(copy.get_HP());
	this->set_MP(copy.get_MP());
	this->set_AD(copy.get_AD());
	this->set_flag(copy.get_flag());
	return (*this);
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap " << get_name() << " is destroyed." << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << get_name() << " asks for a high five!" << std::endl;
}


/* functions */
void FragTrap::attack(const std::string& target)
{
	try
	{
		if (get_HP() < 1)
			throw (std::string("ERR"));
		if (get_MP() < 1)
			throw (get_MP());
		std::cout << "FragTrap "<< \
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

void FragTrap::takeDamage(unsigned int amount)
{
	try
	{
		if (get_HP() == 0)
			throw ("BROKEN");
		if (amount < 0)
			throw (amount);
		std::cout << "FragTrap "<< \
		get_name() << " take " << amount << " points of damage!" << std::endl;
		if (get_HP() - static_cast<int>(amount) <= 0)
			set_HP(0);
		else
			set_HP(get_HP() - static_cast<int>(amount));
	}
	catch (std::string str)
	{
		std::cout << get_name() << " is already broken." << std::endl;
	}
	catch (int num)
	{
		std::cout << "Invalid data value" << std::endl;
		set_flag(false);
	}
}

void FragTrap::beRepaired(unsigned int amount)
{
	try
	{
		if (get_MP() < 1)
			throw ("MP");
		std::cout << "FragTrap " << get_name() << " is repaired " << amount << " points of Health" << std::endl;
		if (get_HP() > INT_MAX - static_cast<int>(amount))
			set_HP(INT_MAX);
		else
			set_HP(get_HP() + static_cast<int>(amount));
		set_MP(get_MP() - 1);
	}
	catch (const char *expn)
	{
		this->Exhaustion();
	}
}
