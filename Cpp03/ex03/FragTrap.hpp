/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 05:19:02 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/30 21:25:03 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# define GATEKEEPER 1

class FragTrap : virtual public ClapTrap
{
	private:
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	public:
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( FragTrap &copy );
		FragTrap &operator=( FragTrap &copy );
		~FragTrap( void );

		void highFivesGuys(void);
};

#endif