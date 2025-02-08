/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:35:26 by jjhang            #+#    #+#             */
/*   Updated: 2024/09/21 02:30:29 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

# define FIRSTNAME 1
# define LASTNAME 2
# define NICKNAME 3
# define PHONENUMBER 4
# define SECRET 5

class	Contact
{
	private:
		std::string	FirstName;
		std::string	LastName;
		std::string NickName;
		std::string	PhoneNumber;
		std::string	DarkestSecret;
	public:
		Contact();
		Contact(std::string FirstName, std::string LastName, \
				std::string NickName, std::string PhoneNumber, std::string DarkestSecret);
		~Contact();
		void	ShowContact();
		std::string	get_data(int type);
		void	set_data(std::string input, int idx);
		void	DeleteLine(int len = 0);
};

//setter getter

#endif