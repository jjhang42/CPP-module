/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:05:11 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/31 23:15:30 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	private:
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