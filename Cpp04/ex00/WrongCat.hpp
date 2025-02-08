/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrongcat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:54:55 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/01 11:22:42 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
	protected:
	public:
		/* OCF */
		WrongCat( void );
		WrongCat( WrongCat const &copy );
		~WrongCat( void );
		WrongCat	&operator=( WrongCat const &copy );

		void	makeSound( void ) const;
};

#endif