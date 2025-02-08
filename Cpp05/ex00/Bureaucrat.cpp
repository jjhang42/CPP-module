/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:49:55 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/05 19:23:56 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : name("jjhang"), grade(1)
{
}

Bureaucrat::Bureaucrat( std::string const name, int grade ) : name(name), grade(grade)
{
	out_of_range( grade );
}

Bureaucrat::Bureaucrat( Bureaucrat const &copy ) : name(copy.name), grade(copy.grade)
{
	out_of_range( grade );
}

Bureaucrat::~Bureaucrat( void )
{

}

Bureaucrat	&Bureaucrat::operator=( Bureaucrat const &copy )
{
	if (this == &copy)
		return (*this);

	out_of_range( grade );
	std::cout << "This is not a recommended method." << std::endl;
	const_cast<std::string &>(name) = copy.name;
	grade = copy.grade;
	return (*this);
}

std::string	Bureaucrat::getName( void ) const
{
	return (name);
}

int	Bureaucrat::getGrade( void ) const
{
	return (grade);
}


Bureaucrat	&Bureaucrat::operator++( void )
{
	this->grade++;
	out_of_range( grade );
	return (*this);
}

Bureaucrat	Bureaucrat::operator++( int )
{
	this->grade++;
	Bureaucrat	temp(*this);
	out_of_range( grade );
	return (temp);
}

Bureaucrat	&Bureaucrat::operator--( void )
{
	this->grade--;
	out_of_range( grade );
	return (*this);
}

Bureaucrat	Bureaucrat::operator--( int )
{
	this->grade--;
	Bureaucrat	temp(*this);
	out_of_range( grade );
	return (temp);
}

const char *Bureaucrat::GradeTooHighException::what( void ) const throw()
{
	return ("Grade is Too High!");
}

const char *Bureaucrat::GradeTooLowException::what( void ) const throw()
{
	return ("Grade is Too Low!");
}

void	Bureaucrat::out_of_range( int grade )
{
	if (grade < 1 || 150 < grade)
	{
		if (grade < 1)
			throw (GradeTooHighException());
		if (150 < grade)
			throw (GradeTooLowException());
	}
}

void	Bureaucrat::ShowStatus( void ) const
{
	std::cout << "=======================================" << std::endl;
	std::cout << " name : " << name << std::endl;
	std::cout << " grade: " << grade << std::endl;
	std::cout << "=======================================" << std::endl;
}

std::ostream	&operator<<( std::ostream &out, Bureaucrat const &ref )
{
	std::cout << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return (out);
}
