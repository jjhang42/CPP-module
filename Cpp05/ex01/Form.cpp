/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:04:53 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/07 23:36:09 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : title("Form"), sign(false), grade(1), execute(1)
{
	out_of_range( grade );
	out_of_range( execute );
}

Form::Form(std::string const title, bool sign, int const grade, int const execute) : title(title), sign(sign), grade(grade), execute(execute)
{
	out_of_range( grade );
	out_of_range( execute );
}

Form::Form( Form const &copy ) : title(copy.title), sign(copy.sign), grade(copy.grade), execute(copy.execute)
{
	out_of_range( grade );
	out_of_range( execute );
}

Form::~Form( void )
{

}

Form	&Form::operator=( Form const &copy )
{
	if (this == &copy)
		return (*this);
	std::cout << "This is not a recommended method." << std::endl;
	const_cast<std::string &>(title) = copy.title;
	sign = copy.sign;
	const_cast<int &>(grade) = copy.grade;
	const_cast<int &>(execute) = copy.execute;
	out_of_range( grade );
	return (*this);
}

std::string Form::getTitle( void ) const
{
	return (title);
}

bool	Form::getSign( void ) const
{
	return (sign);
}

int	Form::getGrade( void ) const
{
	return (grade);
}

int	Form::getExecute( void ) const
{
	return (execute);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

void	Form::out_of_range( int grade )
{
	if (grade < 1 || 150 < grade)
	{
		if (grade < 1)
			throw (GradeTooHighException());
		if (150 < grade)
			throw (GradeTooLowException());
	}
}

void	Form::ShowStatus( void ) const
{
	std::cout << "title  : " << title << std::endl;
	std::cout << "sign   : ";
	if (sign == true)
		std::cout << "signed" << std::endl;
	else
		std::cout << "blank" << std::endl;
	std::cout << "grade  : " << grade << std::endl;
	std::cout << "execute: " << execute << std::endl;
}

void	Form::besigned( Bureaucrat const &ref )
{
	if (ref.getGrade() > this->getGrade())
		throw(GradeTooLowException());
	this->sign = true;
}

std::ostream	&operator<<( std::ostream &out, Form const &ref )
{
	out << "title  : " << ref.getTitle() << "\n";
	out << "sign   : ";
	if (ref.getSign() == true)
		out << "signed\n";
	else
		out << "blank\n";
	out << "grade  : " << ref.getGrade() << "\n";
	out << "execute: " << ref.getExecute() << "\n";
	return (out);
}
