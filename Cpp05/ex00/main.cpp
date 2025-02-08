/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:51:16 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/05 21:03:00 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "< Normal case >" << std::endl;
	Bureaucrat	jjhang("someone", 1);
	jjhang.ShowStatus();

	std::cout << "\n< out of range: constructor case >" << std::endl;
	try
	{
		Bureaucrat	high_level("false man", 0);
		/* is not PRINT */
		high_level.ShowStatus();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat	low_level("false man", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "\n=======================================\n" << std::endl;
	std::cout << " < Normal increase / decrease Case > " << std::endl;
	try
	{
		/* relegation */
		Bureaucrat	relegation("expect lv2", 1);
		relegation++;
		relegation.ShowStatus();
		relegation--;
		relegation.ShowStatus();
		((relegation++)++)++.ShowStatus();
		relegation.ShowStatus();
		relegation--;
		/* exception case: */
		relegation--;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << jjhang << std::endl;
	return (0);
}
