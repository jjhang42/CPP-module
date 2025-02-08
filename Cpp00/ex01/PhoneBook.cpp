/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:35:18 by jjhang            #+#    #+#             */
/*   Updated: 2024/09/13 16:53:35 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	cur_height = 0;
	idx = 0;
	mode = MAINPAGE;
}

PhoneBook::~PhoneBook()
{
}

int	PhoneBook::GetMode(void)
{
	return (this->mode);
}

void	PhoneBook::SetMode(int data)
{
	this->mode = data;
}

void	PhoneBook::SetIdx(int idx)
{
	this->idx = idx;
}

int	PhoneBook::GetIdx(void)
{
	return (this->idx);
}

int		PhoneBook::GetCurHeight(void)
{
	return (this->cur_height);
}

void	PhoneBook::SetCurHeight(int height)
{
	this->cur_height = height;
}

void	PhoneBook::PrintAdd(void)
{
	int	line;

	line = PhoneBook::GetIdx();
	for (int i = 0; i < 5; i++)
	{
		std::cout << "                    ADD MODE                 " << std::endl;
		PrintTableHead();
		PrintLine(line);
		PrintTableTail();
		set_contacts(line, i);
		PhoneBook::SetCurHeight(6);
		PhoneBook::DeletePage();
	}
	SetIdx((line + 1) % SIZE);
}

void	PhoneBook::PrintSearch(void)
{
	std::cout << "                  SEARCH MODE                " << std::endl;
	PrintTableHead();
	for (int line = 0; line < 8; line++)
		PrintLine(line);
	PrintTableTail();
	PhoneBook::SetCurHeight(13);
}

void	PhoneBook::PrintTableHead(void)
{
	std::cout << "┏━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━┓" << std::endl;
	std::cout << "┃\033[44;37m  Index.  | 1st Name | 2nd Name | NickName \033[0m┃" << std::endl;
}

void	PhoneBook::PrintTableTail(void)
{
	std::cout << "┗━━━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━━━┛" << std::endl;
}

void	PhoneBook::PrintTableIndex(int line)
{
	std::string	str;

	std::cout << "┏━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
	str = contacts[line].get_data(FIRSTNAME);
	std::cout << "┃ 1st Name |"; PrintText(str, 32); std::cout << "┃" << std::endl;
	str = contacts[line].get_data(LASTNAME);
	std::cout << "┃ 2nd Name |"; PrintText(str, 32); std::cout << "┃" << std::endl;
	str = contacts[line].get_data(NICKNAME);
	std::cout << "┃ NickName |"; PrintText(str, 32); std::cout << "┃" << std::endl;
	str = contacts[line].get_data(PHONENUMBER);
	std::cout << "┃ PhoneNum.|"; PrintText(str, 32); std::cout << "┃" << std::endl;
	str = contacts[line].get_data(SECRET);
	std::cout << "┃DarkSecret|"; PrintText(str, 32); std::cout << "┃" << std::endl;
	std::cout << "┗━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl;
	std::cout << "Please press the Enter: ";
	std::getline(std::cin, str);
	PhoneBook::SetCurHeight(8);
}

/* 사용할 것!!!! */
bool	PhoneBook::IsPrintableString(std::string& cmd)
{
	for (unsigned long idx = 0; idx < cmd.size(); idx++)
	{
		if (!std::isprint(cmd[idx]))
			return (false);
	}
	return (true);
}

void	PhoneBook::CmdLine(void)
{
	std::string	cmd;

	if (this->mode == MAINPAGE)
	{
		std::cout << "INPUT_CMD: ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
		{
			std::cin.clear();
			std::cin.ignore();
			this->mode = EXIT;
			return;
		}
		if (!PhoneBook::IsPrintableString(cmd))
			return ;
		if (cmd == "ADD" || cmd == "1")
			this->mode = ADD;
		else if (cmd == "SEARCH" || cmd == "2")
			this->mode = SEARCH;
		else if (cmd == "EXIT" || cmd == "3")
			this->mode = EXIT;
	}
}

void	PhoneBook::PrintLine(int line)
{
	std::string	str;

	for (int idx = 0; idx < 4; idx++)
	{
		if (idx == 0)
			std::cout << "┃";
		if (idx != 0)
			str = contacts[line].get_data(idx);
		if (idx != 0)
			PrintText(str, 10);
		else if (idx == 0)
			std::cout << "\033[1m\033[104m\033[97m         " << line + 1 << "\033[0m";
		if (idx != 3)
			std::cout << "|";
	}
	std::cout << "┃";
	std::cout << std::endl;
}

void	PhoneBook::PrintText(std::string str, int size)
{
	int	len = str.size();

	if (len > size) {
		str = str.substr(0, size - 1); str += ".";
		std::cout << str;
	}
	else if (len != size)
	{
		for (int idx = 0; idx < size - len; idx++)
			std::cout << ' ';
		std::cout << str;
	}
	else
		std::cout << str;
}

void	PhoneBook::PrintWelcome(void)
{
	std::cout << "                 jjhang's Phone              " << std::endl;
	std::cout << "     ______   _______  _______  _            " << std::endl;
	std::cout << "    (  ___ \\ (  ___  )(  ___  )| \\    /\\  " << std::endl;
	std::cout << "    | (   ) )| (   ) || (   ) ||  \\  / /    " << std::endl;
	std::cout << "    | (__/ / | |   | || |   | ||  (_/ /      " << std::endl;
	std::cout << "    |  __ (  | |   | || |   | ||   _ (       " << std::endl;
	std::cout << "    | (  \\ \\ | |   | || |   | ||  ( \\ \\  " << std::endl;
	std::cout << "    | )___) )| (___) || (___) ||  /  \\ \\   " << std::endl;
	std::cout << "    |/ \\___/ (_______)(_______)|_/    \\/   " << std::endl;
	std::cout << "=============================================" << std::endl;
	std::cout << "Select a mode: [ADD(1)] [SEARCH(2)] [EXIT(3)]" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	PhoneBook::CmdLine();
	PhoneBook::SetCurHeight(13);
}

void	PhoneBook::PrintExit(void)
{
	std::cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
	std::cout << "┃ *                           *             ┃" << std::endl;
	std::cout << "┃      *       .         *              .   ┃" << std::endl;
	std::cout << "┃          .    [Phone Book]      .      *  ┃" << std::endl;
	std::cout << "┃    .      *       EXIT    *          .    ┃" << std::endl;
	std::cout << "┃      *       *      .         *       *   ┃" << std::endl;
	std::cout << "┃  .               .        .        .      ┃" << std::endl;
	std::cout << "┃      *         Thank you!  *    .         ┃" << std::endl;
	std::cout << "┃   .       .        *       .         .    ┃" << std::endl;
	std::cout << "┃ *                       *       *         ┃" << std::endl;
	std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl;
	std::cout << " Please contact us: jjhang@student.42seoul.kr" << std::endl;
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
	PhoneBook::SetCurHeight(13);
}

void	PhoneBook::DeletePage(void)
{
	unsigned int	len = PhoneBook::GetCurHeight();
	std::cout << "\r";
	for (unsigned int idx = 0; idx < len; idx++)
	{
		std::cout << "\033[A";
		std::cout << "\033[2K\r";
	}
	PhoneBook::SetCurHeight(0);
}

void	PhoneBook::set_contacts(int idx, int i)
{
	std::string	str;

	while (1)
	{
		if (i + 1 == FIRSTNAME)
			std::cout << "First Name: ";
		if (i + 1 == LASTNAME)
			std::cout << "Last Name: ";
		if (i + 1 == NICKNAME)
			std::cout << "Nick Name: ";
		if (i + 1 == PHONENUMBER)
			std::cout << "Phone Number: ";
		if (i + 1 == SECRET)
			std::cout << "Darkest Secret: ";
		std::getline(std::cin, str);
		if (std::cin.eof())
		{
			std::cin.clear();
			std::cin.ignore();
			this->mode = EXIT;
			return;
		}
		if (PhoneBook::IsPrintableString(str) != true)
		{
			std::cout << "\r";
			std::cout << "\033[A";
			std::cout << "\033[2K\r";
			continue;
		}
		for (size_t j = 0; j < str.size(); j++)
		{
			if (str[j] == '\t')
				str[j] = ' ';
		}
		if (str.size() > 0)
			break ;
		PhoneBook::SetCurHeight(6);
		PhoneBook::DeletePage();
		std::cout << "                    ADD MODE                 " << std::endl;
		PrintTableHead();
		PrintLine(idx);
		PrintTableTail();
	}
	contacts[idx].set_data(str, i);
}
