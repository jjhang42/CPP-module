/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 13:03:45 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/04 15:56:51 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
	protected:
	public:
		Ice( void );
		Ice( std::string const &type );
		Ice( Ice const &copy );
		~Ice( void );
		Ice &operator=( Ice const &copy );

		Ice *clone( void ) const;
		void use(ICharacter& target);
};

#endif