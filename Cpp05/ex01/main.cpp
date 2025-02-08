/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:51:16 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/07 23:20:45 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "start" << std::endl;
	Bureaucrat	man1("jjhang", 3);
	Bureaucrat	man2("lv7", 7);
	Form		form("form", false, 5, 3);

	try
	{
		std::cout << "1. out of range: input 0" << std::endl;
		Form	_text("form", false, 0, 5);
	}
	catch(const std::exception& e)
	{
		std::cerr << "exceotion: grade: ";
		std::cerr << e.what() << '\n' << std::endl;
	}
	try
	{
		std::cout << "2. out of range: input 151" << std::endl;
		Form	_text("form", false, 151, 5);
	}
	catch(const std::exception& e)
	{
		std::cerr << "exceotion: grade: ";
		std::cerr << e.what() << '\n' << std::endl;
	}
	try
	{
		std::cout << "3. out of range: input 0" << std::endl;
		Form	_text("form", false, 1, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << "exceotion: execute: ";
		std::cerr << e.what() << '\n' << std::endl;
	}
	try
	{
		std::cout << "4. out of range: input 151231" << std::endl;
		Form	_text("form", false, 1, 151231);
	}
	catch(const std::exception& e)
	{
		std::cerr << "exceotion: execute: ";
		std::cerr << e.what() << '\n' << std::endl;
	}
	/* is able to print member vals? */
	std::cout << "If level 7 tries" << std::endl;
	std::cout << "check function:: >>besigned<<" << std::endl;
	std::cout << "==============================\n";
	form.ShowStatus();
	std::cout << "------------------------------\n";
	try
	{
		std::cout << "[try besigned!]" << std::endl;
		form.besigned(man2);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: ";
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------------------------\n";
	form.ShowStatus();
	man2.signForm(form);
	std::cout << "==============================" << std::endl;

	std::cout << "\n\nif level 5 tries" << std::endl;
	std::cout << man1;
	std::cout << "check function:: >>besigned<<" << std::endl;
	std::cout << "==============================\n";
	form.ShowStatus();
	std::cout << "------------------------------\n";
	try
	{
		std::cout << "[try besigned!]" << std::endl;
		form.besigned(man1);
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: ";
		std::cerr << e.what() << '\n';
	}
	std::cout << "------------------------------\n";
	form.ShowStatus();
	man1.signForm(form);
	std::cout << "==============================" << std::endl;

	return (0);
}
