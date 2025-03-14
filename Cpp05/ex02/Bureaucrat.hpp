/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:49:53 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/10 01:52:30 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const	name;
		int					grade;
		void	out_of_range( int grade );
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw ();
		};
	protected:
	public:
		/* O.C.C.F. */
		Bureaucrat( void );
		Bureaucrat( Bureaucrat const &copy );
		Bureaucrat( std::string const name, int grade );
		~Bureaucrat( void );
		Bureaucrat &operator=( Bureaucrat const &copy );
		std::string	getName( void ) const;
		int			getGrade( void ) const;
		Bureaucrat	&operator++( void );
		Bureaucrat	operator++( int );
		Bureaucrat	&operator--( void );
		Bureaucrat	operator--( int );
		void		ShowStatus( void ) const;
		void		signForm( AForm const &ref ) const;
		void		executeForm(AForm const & form);
};

std::ostream	&operator<<( std::ostream &out, Bureaucrat const &ref );

#endif