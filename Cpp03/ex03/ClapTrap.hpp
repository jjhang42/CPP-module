/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:06:02 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/30 20:49:33 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

# define NORMAL 0

class ClapTrap
{
	protected:
	private:
		std::string	name;
		int			HP;
		int			MP;
		int			AD;
		int			status;
		bool		flag;
	public:
		/* O.C.F. */
		ClapTrap( void );
		ClapTrap( std::string name );
		ClapTrap( ClapTrap &copy );
		~ClapTrap( void );
		ClapTrap &operator=( ClapTrap &copy );

		/* functions */
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		/* abt status */
		void	Showstatus( void );
		void	Exhaustion( void );
		std::string	get_name( void );
		int		get_HP( void );
		int		get_MP( void );
		int		get_AD( void );
		int		get_status( void );
		bool	get_flag( void );
		void	set_HP( int point );
		void	set_MP( int point );
		void	set_AD( int point );
		void	set_status( int point );
		void	set_flag( bool point );
};

#endif