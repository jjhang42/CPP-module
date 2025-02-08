/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:35:51 by jjhang            #+#    #+#             */
/*   Updated: 2024/09/13 16:57:15 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook		PhoneBook;
	std::string		str;
	int				mode;
	int				num;

	std::signal(SIGTSTP, SIG_IGN);
	while (PhoneBook.GetMode() != EXIT && !std::cin.eof())
	{
		PhoneBook.PrintWelcome();
		PhoneBook.DeletePage();
		mode = PhoneBook.GetMode();
		if (mode == SEARCH)
		{
			PhoneBook.PrintSearch();
			std::cout << "Please Press The Number: ";
			num = 0;
			while (!(1 <= num && num <= 8))
			{
				std::getline(std::cin, str);
				num = std::atoi(str.c_str());
				if (!(1 <= num && num <= 8))
				{
					PhoneBook.DeletePage();
					PhoneBook.PrintSearch();
					std::cout << "Please Press The Number: ";
				}
			}
			num--;
			PhoneBook.DeletePage();
			PhoneBook.PrintTableIndex(num);
			PhoneBook.DeletePage();
		}
		if (mode == ADD)
		{
			PhoneBook.PrintAdd();
			PhoneBook.DeletePage();
		}
		if (mode == EXIT)
			break ;
		PhoneBook.SetMode(MAINPAGE);
	}
	PhoneBook.PrintExit();
	return (0);
}
