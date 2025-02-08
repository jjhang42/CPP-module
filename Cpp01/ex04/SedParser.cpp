/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedParser.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:35:48 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/31 04:39:30 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedParser.hpp"

SedParser::SedParser( int argc, char *argv[] )
{
	this->argc = argc;
	this->argv = argv;
	if (1 < argc)
		this->infile_path = argv[1];
}

SedParser::~SedParser( void )
{
}

bool	SedParser::IsValid( void )
{
	if (this->argc != 4)
	{
		std::cerr << "Error: " << this->argv[0] << ": It is not valid parameters." << std::endl;
		return (false);
	}
	return (true);
}

std::string	SedParser::get_outfilename( void )
{
	this->outfile_path = "";

	this->outfile_path = this->infile_path;
	this->outfile_path += ".replace";
	return (this->outfile_path);
}

void	SedParser::set_ifstream( std::ifstream &file )
{
	this->infile = &file;
}

void	SedParser::set_ofstream( std::ofstream &file )
{
	this->outfile = &file;
}

std::string SedParser::replace( size_t pos, size_t len, const std::string &str )
{
	std::string	head = newline.substr(0, pos);
	std::string	tail = newline.substr(pos + len);
	newline = head + str + tail;

	return (newline);
}

void	SedParser::recpy( void )
{
	std::string	s1 = this->argv[2];
	std::string s2 = this->argv[3];
	int			idx;

	idx = 0;
	while (std::getline(*infile, newline))
	{
		size_t	pos;

		if (idx != 0)
			*outfile << std::endl;
		pos = 0;
		pos = newline.find(s1, pos);
		while (s1.size() != 0 && pos != std::string::npos)
		{
			newline = SedParser::replace(pos, s1.size(), s2);
			pos += s2.size();
			pos = newline.find(s1, pos);
		}
		*outfile << newline;
		idx++;
	}
}
