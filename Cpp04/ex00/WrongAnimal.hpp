/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:43:45 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/01 11:23:18 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	private:
	protected:
		std::string	type;
	public:
		/* OCF */
		WrongAnimal( void );
		WrongAnimal( WrongAnimal const &copy );
		~WrongAnimal( void );
		WrongAnimal	&operator=( WrongAnimal const &copy );

		void	makeSound( void ) const;
		void	setType( std::string type );
		std::string	getType( void ) const;
};

#endif