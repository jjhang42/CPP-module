/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedParser.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:21:40 by jjhang            #+#    #+#             */
/*   Updated: 2024/10/31 04:39:05 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_PARSER_HPP
# define SED_PARSER_HPP

# include <iostream>
# include <fstream>
# include <string>

class SedParser
{
	private:
		int		argc;
		char	**argv;
		std::string		infile_path;
		std::string		outfile_path;
		std::ifstream	*infile;
		std::ofstream	*outfile;
		std::string		newline;
	public:
		SedParser( int argc, char *argv[] );
		~SedParser( void );
		bool	IsValid( void );
		std::string	get_outfilename( void );
		void		set_ifstream( std::ifstream &file );
		void		set_ofstream( std::ofstream &file );
		void		recpy( void );
		std::string	replace(size_t pos, size_t len, const std::string &str );
};

#endif