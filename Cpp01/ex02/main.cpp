/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 07:50:46 by jjhang            #+#    #+#             */
/*   Updated: 2024/09/28 08:15:25 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "============[Address held by]============" << std::endl;
	std::cout << "STR address: " << &str << std::endl;
	std::cout << "PTR address: " << stringPTR << std::endl;
	std::cout << "REF address: " << &stringREF << std::endl << std::endl;

	std::cout << "============[ Values ]===========" << std::endl;
	std::cout << "STR Value: " << str << std::endl;
	std::cout << "PTR Value: " << *stringPTR << std::endl;
	std::cout << "REF Value: " << stringREF << std::endl;
	return (0);
}