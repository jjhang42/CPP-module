/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 03:27:04 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/13 08:52:44 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
/* doc list */

enum e_FormType
{
	ShrubberyCreation,
	RobotomyRequest,
	PresidentialPardon,
	ERROR
};

class Intern
{
	private:
		class InvalidArg : public std::exception
		{
			const char *what () const throw ();
		};
	protected:
	public:
		Intern( void );
		~Intern( void );
		Intern( Intern const &copy );
		Intern	&operator=( Intern const &copy );

		AForm	*makeForm(std::string const &Form, std::string const &Target);
};

#endif