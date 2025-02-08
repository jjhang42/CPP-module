/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:06:19 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/04 14:05:14 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl	compi;

	compi.complain("DEBUG");
	compi.complain("INFO");
	compi.complain("WARNING");
	compi.complain("ERROR");
	return (0);
}