/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:45:46 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/13 00:04:09 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
	protected:
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string &target );
		~RobotomyRequestForm( void );
		RobotomyRequestForm	&operator=( RobotomyRequestForm &copy );
		void	SubExecute( void ) const;
};

#endif