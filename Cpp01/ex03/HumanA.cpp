/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 04:00:35 by jjhang            #+#    #+#             */
/*   Updated: 2024/09/29 11:44:46 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon_type) : name(name), weapon(weapon_type)
{
}

void	HumanA::attack( void )
{
	std::cout << this->name << " attacked with " << weapon.getType() << "!" << std::endl;
}
