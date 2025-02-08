/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:51:16 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/10 03:18:29 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::string	name("HOME");
	Bureaucrat	jjhang1("jjhang", 150);
	Bureaucrat	jjhang2("jjhang", 5);
	AForm *tree = new ShrubberyCreationForm(name);
	/* try to execute */
	try
	{
		tree->execute(jjhang1); // failed
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	/* get signed */
	try
	{
		/* code */
		tree->besigned(jjhang2);
		tree->execute(jjhang1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		/* code */
		tree->execute(jjhang2);
		tree->ShowStatus();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;
	std::string	robot_target("target");
	AForm	*Robot = new RobotomyRequestForm(robot_target);
	Robot->besigned(jjhang2);
	Robot->execute(jjhang2);

	std::string prisoner("prisoner");
	AForm	*president = new PresidentialPardonForm(prisoner);
	president->besigned(jjhang2);
	// president->execute(jjhang2);
	std::cout << "try to execute: lv 150" << std::endl;
	try
	{
		/* code */
		jjhang1.executeForm(*president);
	}
	catch(const std::exception& e)
	{
		std::cerr << "exception: ";
		std::cerr << e.what() << '\n';
	}
	std::cout << "try to execute: lv 5" << std::endl;
	jjhang2.executeForm(*president);

	return (0);
}
