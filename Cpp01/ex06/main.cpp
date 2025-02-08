/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:06:19 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/04 14:22:10 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl	compi;
	int		lev;

	if (!(1 < argc && argc < 3))
	{
		std::cerr << "Error: Invalid parameters" << std::endl;
		return (1);
	}
	lev = compi.get_token_N(argv[1]);
	switch (lev)
	{
		case DEBUG:
			compi.complain("DEBUG");
		case INFO:
			compi.complain("INFO");
		case WARNING:
			compi.complain("WARNING");
		case ERROR:
			compi.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}