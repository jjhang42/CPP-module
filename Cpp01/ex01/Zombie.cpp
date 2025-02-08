/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:48:03 by jjhang            #+#    #+#             */
/*   Updated: 2024/09/28 07:11:39 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->name = "Faceless One";
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << this->name << " is created." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " zombie is dead." << std::endl;
}

void	Zombie::zombie_setter(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
