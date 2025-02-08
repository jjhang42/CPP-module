/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:00:32 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/10 01:43:23 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
	protected:
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string &target );
		~ShrubberyCreationForm( void );
		ShrubberyCreationForm	&operator=( ShrubberyCreationForm &copy );
		void	SubExecute( void ) const;
};

#endif