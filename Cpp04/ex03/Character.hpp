/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 06:23:39 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/04 15:55:52 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define SLOT_SIZE 4

class Character : virtual public ICharacter
{
	private:
		std::string		name;
		AMateria		*slot[SLOT_SIZE];
		unsigned int	cnt;
	protected:
	public:
		/* O.C.F. */
		Character( void );
		Character( std::string name );
		Character( Character const &copy );
		~Character( void );
		Character	&operator=( Character const &copy );

		/* Func */
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};
