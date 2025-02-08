/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:18:51 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/02 16:41:49 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedParser.hpp"

int	main(int argc, char *argv[])
{
	/* invalid check */
	SedParser	parser(argc, argv);
	if (parser.IsValid() == false)
		return (1);
	std::ifstream	infile(argv[1], std::ios::in);
	if (!infile)
	{
		std::cerr << "Error: " << argv[1] << ": Can not open infile path." << std::endl;
		return (1);
	}
	parser.set_ifstream(infile);
	std::ofstream	outfile(parser.get_outfilename());
	if (!outfile)
	{
		std::cerr << "Error: " << ": Can not open outfile." << std::endl;
		return (1);
	}
	parser.set_ofstream(outfile);
	parser.recpy();
	return (0);
}
