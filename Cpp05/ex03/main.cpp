/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:51:16 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/13 08:54:06 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	jjhang("jjhang", 1);
	Intern		intern;
	try
	{
		/* code */
		AForm		*tree = intern.makeForm("ShrubberyCreationForm", "HOME");
		tree->besigned(jjhang);
		tree->execute(jjhang);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		/* code */
		AForm		*Robo = intern.makeForm("RobotomyRequestForm", "syber");
		Robo->besigned(jjhang);
		Robo->execute(jjhang);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		/* code */
		AForm		*presidential = intern.makeForm("PresidentialPardonForm", "Trump");
		presidential->besigned(jjhang);
		presidential->execute(jjhang);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		/* invalidForm */
		AForm		*InvalidForm = intern.makeForm("asdf", "Trump");
		InvalidForm->besigned(jjhang);
		InvalidForm->execute(jjhang);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
