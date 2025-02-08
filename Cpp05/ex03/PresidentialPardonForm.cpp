/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:59:28 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/10 11:18:20 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void )
{
	setTitle("PresidentialPardonForm");
	setTarget("Default");
	setSign( false );
	setGrade( 25 );
	setExecute( 5 );
}

PresidentialPardonForm::PresidentialPardonForm( std::string &target )
{
	setTitle("PresidentialPardonForm");
	setTarget(target);
	setSign( false );
	setGrade( 25 );
	setExecute( 5 );
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( PresidentialPardonForm &copy )
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

void	PresidentialPardonForm::SubExecute( void ) const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." <<std::endl;
}