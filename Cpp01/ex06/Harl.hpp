/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:06:44 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/04 13:49:08 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define DEBUG 0
# define INFO 1
# define WARNING 2
# define ERROR 3

class Harl
{
	private:
		void	debug( void );
		void	info( void );
		void	warning(void );
		void	error( void );
		void	(Harl::*ptr[4])( void );
	public:
		Harl( void );
		~Harl( void );
		int		get_token_N( std::string level );
		void	complain(std::string level);
};

#endif