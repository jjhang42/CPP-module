/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:00:11 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/01 14:34:59 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main( void )
{
	Animal	*meta[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			meta[i] = new(Dog);
		else
			meta[i] = new(Cat);
	}

	for (int i = 0; i < 10; i++)
		delete meta[i];
	std::cout << "==============================" << std::endl;
	Dog *a = new Dog();
	Dog	*b = new Dog();

	*b = *a;
	delete a;
	delete b;
	std::cout << "==============================" << std::endl;
	// while (1)
	// {
	// }
	return (0);
}