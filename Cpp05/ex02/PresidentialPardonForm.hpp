/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:59:35 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/10 01:43:07 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class PresidentialPardonForm : public AForm
{
	private:
	protected:
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string &target );
		~PresidentialPardonForm( void );
		PresidentialPardonForm	&operator=( PresidentialPardonForm &copy );
		void	SubExecute( void ) const;
};

#endif