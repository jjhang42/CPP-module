/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:04:51 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/10 01:42:58 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	title;
		std::string			target;
		bool				sign;
		int	const			grade;
		int	const			exe;
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
		class IsNotSigned : public std::exception
		{
			public:
				const char *what() const throw();
		};
	protected:
	public:
		/* O.C.C.F. */
		AForm( void );
		AForm(std::string const title, bool sign, int const grade, int const execute);
		AForm( AForm const &copy );
		virtual ~AForm( void );
		AForm	&operator=( AForm const &copy );

		std::string getTitle( void ) const;
		std::string	getTarget( void ) const;
		bool		getSign( void ) const;
		int			getGrade( void ) const;
		int			getExecute( void ) const;

		void		out_of_range( int grade ) const;
		void		ShowStatus( void ) const;

		void		setTitle( std::string title );
		void		setTarget( std::string title );
		void		setSign( int sign );
		void		setGrade( int const grade );
		void		setExecute( int const exe );

		void		besigned( Bureaucrat const &ref );
		void		execute(Bureaucrat const & executor) const;
		virtual	void	SubExecute( void ) const = 0;
};

std::ostream	&operator<<( std::ostream &out, AForm const &ref );
#endif