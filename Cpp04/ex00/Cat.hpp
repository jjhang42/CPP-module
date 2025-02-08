/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:17:41 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/31 23:18:39 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	private:
	protected:
	public:
		/* OCF */
		Cat( void );
		Cat( Cat const &copy );
		~Cat( void );
		Cat	&operator=( Cat const &copy );

		void	makeSound( void ) const;
};

#endif