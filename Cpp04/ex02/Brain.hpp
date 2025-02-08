/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:33:00 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/01 13:04:30 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	protected:
	private:
		std::string	ideas[100];
	public:
		Brain( void );
		Brain( Brain const &copy );
		~Brain( void );
		Brain &operator=( Brain const &copy );
};

#endif