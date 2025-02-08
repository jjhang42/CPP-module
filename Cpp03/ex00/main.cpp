/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:05:27 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/30 20:48:09 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	Mark("Mark I");

	Mark.attack("scarecrow");
	Mark.beRepaired( 2 );
	Mark.Showstatus();
	Mark.takeDamage( 20 );
	Mark.Showstatus();
	Mark.attack("scarecrow");
	for (int i = 0; i < 9; i++)
	{
		Mark.beRepaired(2);
		Mark.Showstatus();
	}
	return (0);
}