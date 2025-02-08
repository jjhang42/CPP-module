/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 03:27:28 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/13 08:52:35 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void )
{

}

Intern::~Intern( void )
{

}

Intern::Intern( Intern const &copy )
{
	*this = copy;
}

Intern	&Intern::operator=( Intern const &copy )
{
	if (this == &copy)
		return (*this);
	return (*this);
}

static e_FormType	getFromType(std::string const &Form)
{
	if (Form == "ShrubberyCreationForm")
		return (ShrubberyCreation);
	if (Form == "RobotomyRequestForm")
		return (RobotomyRequest);
	if (Form == "PresidentialPardonForm")
		return (PresidentialPardon);
	return (ERROR);
}

const char	*Intern::InvalidArg::what() const throw ()
{
	return ("It is Invalid argmunet.");
}

AForm	*Intern::makeForm(std::string const &Form, std::string const &Target)
{
	std::string	target;

	target = Target;
	switch (getFromType(Form))
	{
		case ShrubberyCreation :
		{
			std::cout << "Intern creates ShrubberyCreation" << std::endl;
			return (new ShrubberyCreationForm(target));
		}
		case RobotomyRequest :
		{
			std::cout << "Intern creates RobotomyRequest" << std::endl;
			return (new RobotomyRequestForm(target));
		}
		case PresidentialPardon :
		{
			std::cout << "Intern creates PresidentialPardon" << std::endl;
			return (new PresidentialPardonForm(target));
		}
		default :
		{
			throw (InvalidArg());
		}
	}
	return (NULL);
}
