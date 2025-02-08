/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 03:20:35 by jjhang            #+#    #+#             */
/*   Updated: 2024/09/29 11:23:34 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	this->name = "A trained fist";
}

Weapon::Weapon(std::string weapon) : name(weapon)
{
}

const std::string	&Weapon::getType( void ) const
{
	return (this->name);
}

void	Weapon::setType(std::string weapon)
{
	this->name = weapon;
}
