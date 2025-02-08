/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:04:51 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/06 20:34:36 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	title;
		bool				sign;
		int	const			grade;
		int	const			execute;
		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
	protected:
	public:
		/* O.C.C.F. */
		Form( void );
		Form(std::string const title, bool sign, int const grade, int const execute);
		Form( Form const &copy );
		~Form( void );
		Form	&operator=( Form const &copy );

		std::string getTitle( void ) const;
		bool		getSign( void ) const;
		int			getGrade( void ) const;
		int			getExecute( void ) const;
		void		out_of_range( int grade );
		void		ShowStatus( void ) const;
		void		besigned( Bureaucrat const &ref );
};

std::ostream	&operator<<( std::ostream &out, Form const &ref );
#endif