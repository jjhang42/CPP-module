/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:05:27 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/30 20:57:16 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	Mark("Mark II");

	Mark.attack("scarecrow");
	Mark.beRepaired( 20 );
	Mark.guardGate();
	Mark.guardGate();
	Mark.takeDamage( 10000 );
	Mark.guardGate();
	Mark.attack("other");
	return (0);
}