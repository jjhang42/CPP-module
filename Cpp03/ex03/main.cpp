/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:05:27 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/30 23:07:08 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	Mark("MAKR IV");

	// DiamondTrap(Mark).whoAmI();
	Mark.whoAmI();
	std::cout << "+++++++++++++++++++" << std::endl;
	Mark.ScavTrap::attack("target");
	std::cout << "+++++++++++++++++++" << std::endl;
	return (0);
}