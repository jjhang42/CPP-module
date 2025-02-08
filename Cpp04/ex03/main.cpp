/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 06:06:46 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/04 16:16:09 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Character.hpp"

int	main(void)
{
	Character	player;
	Character	monster("Monster");

	AMateria	*ice = new Ice();
	player.equip(ice);
	player.use(0, monster);

	delete ice;
	return (0);
}