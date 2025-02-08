/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:32:38 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/01 13:17:56 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << "BRAIN!!!!!!" << std::endl;
}

Brain::Brain( Brain const &copy )
{
	std::cout << "BRAIN!!!!!!COPY CONSTRUCTOR!!!" << std::endl;
	*this = copy;
}

Brain::~Brain( void )
{
	std::cout << "BRAIN DESTRUCTOR:(" << std::endl;
}

Brain	&Brain::operator=( Brain const &copy )
{
	if (this == &copy)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	return (*this);
}
