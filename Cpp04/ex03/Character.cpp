/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 06:31:46 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/04 16:17:32 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : name("jjhang")
{
	if (DEBUG == true)
		std::cout << "Character was born!" << std::endl;
	for (int i = 0; i < SLOT_SIZE; i++)
		slot[i] = NULL;
	cnt = 0;
}

Character::Character( std::string name ) : name(name)
{
	if (DEBUG == true)
		std::cout << "Character was born!" << std::endl;
	for (int i = 0; i < SLOT_SIZE; i++)
		slot[i] = NULL;
	cnt = 0;
}

Character::Character( Character const &copy )
{
	*this = copy;
	cnt = 0;
}

Character::~Character( void )
{
}

Character &Character::operator=( Character const &copy )
{
	if (this == &copy)
		return (*this);
	name = copy.name;
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (slot[i] != NULL)
		{
			delete slot[i];
			slot[i] = NULL;
		}
		slot[i] = copy.slot[i];
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	int	c = 0;
	for (int i = 0; i < SLOT_SIZE; i++)
	{
		if (slot[i] == NULL)
			break;
		else
			c++;
	}
	if (c == SLOT_SIZE)
	{
		std::cout << "Materia is full." << std::endl;
		return ;
	}
	if (slot[cnt % SLOT_SIZE] == NULL)
		slot[cnt % SLOT_SIZE] = m;
	else if (slot[c] == NULL)
		slot[cnt % SLOT_SIZE] = m;
	cnt++;
}

void Character::unequip(int idx)
{
	if (idx >= SLOT_SIZE)
	{
		std::cout << "ERROR: Invalid value." << std::endl;
		return ;
	}
	if (slot[idx] == NULL)
	{
		std::cout << "Materia does not exist." << std::endl;
		return ;
	}
	slot[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= SLOT_SIZE)
	{
		std::cout << "ERROR: Invalid value." << std::endl;
		return ;
	}
	if (slot[idx] == NULL)
	{
		std::cout << "Materia does not exist." << std::endl;
		return ;
	}
	slot[idx]->use(target);
}
