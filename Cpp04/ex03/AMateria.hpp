/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 06:07:37 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/04 15:56:56 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMTERIA_HPP
# define AMTERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

#define DEBUG 1

class	ICharacter;

/* 32 -> 56 -> 80 */
class AMateria
{
	private:
	protected:
		std::string	type;
	public:
		AMateria( void );
		AMateria( std::string const &type );
		AMateria( AMateria const &copy );
		virtual	~AMateria( void );
		AMateria &operator=( AMateria const &copy );

		std::string const & getType( void ) const; //Returns the materia type
		virtual AMateria* clone( void ) const = 0;
		virtual void use(ICharacter& target);
};

#endif