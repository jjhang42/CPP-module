/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:04:53 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/10 03:07:32 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( void ) : title("Form"), sign(false), grade(1), exe(1)
{
	out_of_range( grade );
	out_of_range( exe );
}

AForm::AForm(std::string const title, bool sign, int const grade, int const exe) : title(title), sign(sign), grade(grade), exe(exe)
{
	out_of_range( grade );
	out_of_range( exe );
}

AForm::AForm( AForm const &copy ) : title(copy.title), sign(copy.sign), grade(copy.grade), exe(copy.exe)
{
	out_of_range( grade );
	out_of_range( exe );
}

AForm::~AForm( void )
{

}

AForm	&AForm::operator=( AForm const &copy )
{
	if (this == &copy)
		return (*this);
	std::cout << "This is not a recommended method." << std::endl;
	const_cast<std::string &>(title) = copy.title;
	sign = copy.sign;
	const_cast<int &>(grade) = copy.grade;
	const_cast<int &>(exe) = copy.exe;
	out_of_range( grade );
	return (*this);
}

std::string AForm::getTitle( void ) const
{
	return (title);
}

std::string AForm::getTarget( void ) const
{
	return (target);
}

bool	AForm::getSign( void ) const
{
	return (sign);
}

int	AForm::getGrade( void ) const
{
	return (grade);
}

int	AForm::getExecute( void ) const
{
	return (exe);
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char	*AForm::IsNotSigned::what() const throw()
{
	return ("This document is not signed!");
}

void	AForm::out_of_range( int grade ) const
{
	if (grade < 1 || 150 < grade)
	{
		if (grade < 1)
			throw (GradeTooHighException());
		if (150 < grade)
			throw (GradeTooLowException());
	}
}

void	AForm::ShowStatus( void ) const
{
	std::cout << "title  : " << title << std::endl;
	std::cout << "sign   : ";
	if (sign == true)
		std::cout << "signed" << std::endl;
	else
		std::cout << "blank" << std::endl;
	std::cout << "grade  : " << grade << std::endl;
	std::cout << "exe: " << exe << std::endl;
}

void	AForm::besigned( Bureaucrat const &ref )
{
	if (ref.getGrade() > this->getGrade())
		throw(GradeTooLowException());
	this->sign = true;
}

void	AForm::setTitle( std::string const title )
{
	const_cast<std::string &>(this->title) = title;
}

void	AForm::setTarget( std::string const target )
{
	const_cast<std::string &>(this->target) = target;
}

void	AForm::setSign( int sign )
{
	this->sign = sign;
}

void	AForm::setGrade( int const grade )
{
	const_cast<int &>(this->grade) = grade;
}

void	AForm::setExecute( int const exe )
{
	const_cast<int &>(this->exe) = exe;
}

std::ostream	&operator<<( std::ostream &out, AForm const &ref )
{
	out << "title  : " << ref.getTitle() << "\n";
	out << "sign   : ";
	if (ref.getSign() == true)
		out << "signed\n";
	else
		out << "blank\n";
	out << "grade  : " << ref.getGrade() << "\n";
	out << "exe: " << ref.getExecute() << "\n";
	return (out);
}

void		AForm::execute(Bureaucrat const & executor) const
{
	/* check:  */
	if (getSign() == false)
		throw (IsNotSigned());
	if (getExecute() < executor.getGrade())
		throw (GradeTooLowException());
	SubExecute();
}
