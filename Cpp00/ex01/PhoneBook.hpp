/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 09:35:20 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/02 03:08:51 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <csignal>
# include <cctype>
# include "Contact.hpp"

# define MAINPAGE 0
# define ADD 1
# define SEARCH 2
# define EXIT 3

# define SIZE 8
# define HEIGHT 13
class	PhoneBook
{
	private:
		Contact contacts[SIZE];
		int		idx;
		int		mode;
		int		cur_height;
	public:
		PhoneBook();
		~PhoneBook();
		int			GetMode(void);
		void		SetMode(int mode = MAINPAGE);
		int			GetIdx(void);
		void		SetIdx(int idx);
		int			GetCurHeight(void);
		void		SetCurHeight(int height);
		void		PrintAdd(void);
		void		PrintSearch(void);
		void		PrintTableHead(void);
		void		PrintTableTail(void);
		void		PrintTableIndex(int line);
		void		PrintText(std::string str, int size);
		void		CmdLine(void);
		void		PrintLine(int line);
		void		set_contacts(int idx, int i);
		void		PrintWelcome(void);
		void		PrintExit(void);
		void		DeletePage(void);
		bool		IsPrintableString(std::string& cmd);
};

#endif