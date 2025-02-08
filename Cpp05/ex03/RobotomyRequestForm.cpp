/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:45:35 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/10 11:18:04 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void )
{
	setTitle("RobotomyRequestForm");
	setTarget("Default");
	setSign( false );
	setGrade( 72 );
	setExecute( 45 );
}

RobotomyRequestForm::RobotomyRequestForm( std::string &target )
{
	setTitle("RobotomyRequestForm");
	setTarget(target);
	setSign( false );
	setGrade( 72 );
	setExecute( 45 );
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( RobotomyRequestForm &copy )
{
	if (this == &copy)
		return (*this);
	setTitle(copy.getTitle());
	setTarget(copy.getTarget());
	setSign(copy.getSign());
	setGrade(copy.getGrade());
	setExecute(copy.getExecute());
	return (*this);
}

void	RobotomyRequestForm::SubExecute( void ) const
{
	int	judge = 0;
	srand(static_cast<unsigned int>(time(0)));
	std::cout << "Drill: Drrrrrr drr drrrrrrrr" << std::endl;
	std::cout << "=======Success Judgment Committee=======" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		judge += (rand() % 2);
		std::cout << "result" << i << ": " << judge % 2 << std::endl;
	}
	std::cout << "========================================" << std::endl;
	std::cout << getTarget();
	if (judge > 1)
		std::cout << " has been robotomized successfully" << std::endl;
	else
		std::cout << " failed to robotize." << std::endl;
}