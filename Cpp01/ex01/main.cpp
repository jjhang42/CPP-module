/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 02:08:36 by jjhang            #+#    #+#             */
/*   Updated: 2024/09/28 07:31:39 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// void	ss(void)
// {
// 	system("leaks Moar_brainz");
// }

int	main(void)
{
	Zombie	*target;
	int		N = 3;

	target = zombieHorde(N, "jjhang");
	for (int i = 0; i < N; i++)
	{
		target[i].announce();
	}
	delete [] target;
	// ss();
	return (0);
}