/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:35:31 by jjhang            #+#    #+#             */
/*   Updated: 2024/09/11 14:01:38 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	std::string	BaseData = "        ";

	FirstName = BaseData;
	LastName = BaseData;
	NickName = BaseData;
	PhoneNumber = BaseData;
	DarkestSecret = BaseData;
}

Contact::Contact(std::string FirstName, std::string LastName, \
		std::string NickName, std::string PhoneNumber, std::string DarkestSecret)
{
	this->FirstName = FirstName;
	this->LastName = LastName;
	this->NickName = NickName;
	this->PhoneNumber = PhoneNumber;
	this->DarkestSecret = DarkestSecret;
}
Contact::~Contact()
{
}

void	Contact::ShowContact()
{
	std::cout << this->FirstName << std::endl;
	std::cout << this->LastName << std::endl;
	std::cout << this->PhoneNumber << std::endl;
	std::cout << this->DarkestSecret << std::endl;
}

std::string	Contact::get_data(int type)
{
	if (type == FIRSTNAME)
		return (this->FirstName);
	if (type == LASTNAME)
		return (this->LastName);
	if (type == NICKNAME)
		return (this->NickName);
	if (type == PHONENUMBER)
		return (this->PhoneNumber);
	return (this->DarkestSecret);
}

void	Contact::DeleteLine(int len)
{
	std::cout << "\r";
	for (int idx = 0; idx < len; idx++)
	{
		std::cout << "\033[A";
		std::cout << "\033[2K\r";
	}
}

void	Contact::set_data(std::string input, int type)
{
	if (type == 0)
		this->FirstName = input;
	if (type == 1)
		this->LastName = input;
	if (type == 2)
		this->NickName = input;
	if (type == 3)
		this->PhoneNumber = input;
	if (type == 4)
		this->DarkestSecret = input;
}
