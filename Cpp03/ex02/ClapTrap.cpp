/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:06:01 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/30 20:46:43 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : HP(10), MP(10), AD(0), flag(true), status(NORMAL), name("ClapTrap")
{
	std::cout << name << " is created." << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : HP(10), MP(10), AD(0), flag(true), status(NORMAL), name(name)
{
	std::cout << name << " is created." << std::endl;
}

ClapTrap::ClapTrap( ClapTrap &copy )
{
	std::cout << name << " has been copied." << std::endl;
	this->name = copy.name;
	this->HP = copy.HP;
	this->MP = copy.MP;
	this->AD = copy.AD;
	this->status = copy.status;
	this->flag = true;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << name << " is destroyed." << std::endl;
}

ClapTrap &ClapTrap::operator=( ClapTrap &copy )
{
	if (this == &copy)
		return (*this);
	std::cout << name << " has been copied by operator." << std::endl;
	this->name = copy.name;
	this->HP = copy.HP;
	this->MP = copy.MP;
	this->AD = copy.AD;
	this->status = copy.status;
	this->flag = true;
	return (*this);
}

/* functions */
void ClapTrap::attack(const std::string& target)
{
	try
	{
		if (this->HP < 1)
			throw (std::string("ERR"));
		if (this->MP < 1)
			throw (this->MP);
		std::cout << "ClapTrap "<< \
			name << " attacks " << target << ", causing " << AD << " points of damage!" << std::endl;
		this->MP -= 1;
	}
	catch (int num)
	{
		this->Exhaustion();
	}
	catch (std::string err)
	{
		this->HP = 0;
		this->Exhaustion();
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	try
	{
		if (this->HP == 0)
			throw ("BROKEN");
		if (amount < 0)
			throw (amount);
		std::cout << "ClapTrap "<< \
		name << " take " << amount << " points of damage!" << std::endl;
		if (this->HP - static_cast<int>(amount) <= 0)
			this->HP = 0;
		else
			this->HP -= amount;
	}
	catch (std::string str)
	{
		std::cout << name << " is already broken." << std::endl;
	}
	catch (int num)
	{
		std::cout << "Invalid data value" << std::endl;
		this->flag = false;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	try
	{
		if (this->MP < 1)
			throw ("MP");
		std::cout << "ClapTrap " << name << " is repaired " << amount << " points of Health" << std::endl;
		if (this->HP > INT_MAX - amount)
			this->HP = INT_MAX;
		else
			this->HP += amount;
		this->MP -= 1;
	}
	catch (const char *expn)
	{
		this->Exhaustion();
	}
}

void	ClapTrap::Showstatus( void )
{
	std::cout << "========================" << std::endl;
	std::cout << name << "'s status" << std::endl;
	std::cout << "HP: " << HP << std::endl;
	std::cout << "MP: " << MP << std::endl;
	std::cout << "AD: " << AD << std::endl;
	std::cout << "========================" << std::endl;
}

void	ClapTrap::Exhaustion( void )
{
	std::cout << "ClapTrap " << "is exhausted. ";
	if (this->HP == 0)
	{
		std::cout << "ClapTrap's HP is " << this->HP << ".";
	}
	else
	{
		std::cout << "ClapTrap's MP is " << this->MP << ".";
	}
	std::cout << std::endl;
}

std::string	ClapTrap::get_name( void )
{
	return (this->name);
}

int	ClapTrap::get_HP( void )
{
	return (this->HP);
}

int	ClapTrap::get_MP( void )
{
	return (this->MP);
}

int	ClapTrap::get_AD( void )
{
	return (this->AD);
}

int	ClapTrap::get_status( void )
{
	return (this->status);
}

bool	ClapTrap::get_flag( void )
{
	return (this->flag);
}

void	ClapTrap::set_HP( int point )
{
	this->HP = point;
}

void	ClapTrap::set_MP( int point )
{
	this->MP = point;
}

void	ClapTrap::set_AD( int point )
{
	this->AD = point;
}

void	ClapTrap::set_status( int point )
{
	this->status = point;
}

void	ClapTrap::set_flag( bool point )
{
	this->flag = point;
}
