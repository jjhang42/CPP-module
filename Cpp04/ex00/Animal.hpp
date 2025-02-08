/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:05:11 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/31 23:16:08 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	private:
	protected:
		std::string	type;
	public:
		/* OCF */
		Animal( void );
		Animal( Animal const &copy );
		virtual	~Animal( void );
		Animal	&operator=( Animal const &copy );

		virtual void	makeSound( void ) const;
		void	setType( std::string type );
		std::string	getType( void ) const;
};

#endif