/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 05:19:02 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/30 23:07:39 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# define GATEKEEPER 1

class ScavTrap : virtual public ClapTrap
{
	private:
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( ScavTrap &copy );
		ScavTrap &operator=( ScavTrap &copy );
		~ScavTrap( void );

		void	attack(const std::string& target);
		void	guardGate( void );
};

#endif