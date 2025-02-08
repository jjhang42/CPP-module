/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:38:16 by jjhang            #+#    #+#             */
/*   Updated: 2024/09/28 07:22:42 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie*				target;
	std::stringstream	ss;

	target = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		ss << (i + 1);
		target[i].zombie_setter(name + "_" + ss.str());
		ss.str("");
	}
	return (target);
}

