/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:05:11 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/01 14:01:39 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*brain;
	protected:
	public:
		/* OCF */
		Dog( void );
		Dog( Dog const &copy );
		~Dog( void );
		Dog	&operator=( Dog const &copy );

		void	makeSound( void ) const;
};

#endif