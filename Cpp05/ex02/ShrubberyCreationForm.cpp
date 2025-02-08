/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 21:00:19 by jjhang            #+#    #+#             */
/*   Updated: 2024/11/10 02:16:16 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void )
{
	setTitle("ShrubberyCreation");
	setTarget("Default");
	setSign( false );
	setGrade( 145 );
	setExecute( 137 );
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string &target )
{
	setTitle("ShrubberyCreation");
	setTarget(target);
	setSign( false );
	setGrade( 145 );
	setExecute( 137 );
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( ShrubberyCreationForm &copy )
{
	if (this == &copy)
		return (*this);
	setTitle(copy.getTitle());
	setTarget(copy.getTarget());
	setSign(copy.getSign());
	setGrade(copy.getGrade());
	setExecute(copy.getExecute());
	return (*this);
}

void	ShrubberyCreationForm::SubExecute(void ) const
{
	std::string		filename = getTarget() + "_shrubbery";
	std::ofstream	outfile(filename);
	if (!outfile)
	{
		std::cerr << "Error: Open failed" << std::endl;
		return ;
	}

	const char* tree1 = "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⠾⠿⠿⢷⣶⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣶⡟⠍⡐⠨⢐⢐⢀⢂⠙⢿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⢏⠐⡈⠄⡑⠠⢂⢐⠐⠨⢀⠻⡿⡾⠿⢾⣶⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⢸⣿⠠⢁⠂⠅⠂⠅⡂⢂⠌⠌⡐⠨⢐⠠⢁⠂⢄⠙⢿⣶⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡾⠿⠻⠻⠻⡈⡐⠨⢈⠌⡐⡐⡐⠠⡁⡂⠅⡂⠌⡐⠨⢐⠨⢀⢻⣧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⡄⠄⢌⠐⡁⠅⡁⡂⠂⠅⡂⢂⠂⠔⠠⡁⡂⠄⠅⠄⠅⠂⠅⡂⢂⠢⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⠁⠅⡂⠌⠄⠅⢂⠂⠅⡁⡂⡂⠅⢊⢐⠠⢂⢁⢊⠨⠈⢌⠐⠄⡡⢐⣼⣟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣷⢈⢐⠠⠡⠨⢈⢐⠨⢐⢐⠠⠂⢌⢐⠠⠂⡂⢂⢐⠨⢈⢐⠨⢐⠐⡘⠻⠻⠿⣶⣤⡀⠀⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣘⣿⣆⢐⠨⠠⢑⠐⡐⡈⠄⡂⡐⡁⡂⠔⠠⡁⡂⠅⡐⠨⢀⢂⠂⡂⡂⡂⠅⡡⠨⠐⡙⣿⣦⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⠀⢀⣴⡿⢛⠙⠅⡂⡐⡁⡂⢂⠂⠄⢅⠐⠄⡂⣴⡡⠁⠔⢐⠈⠄⠅⡂⢂⠌⠄⢂⠄⠅⡐⠨⢐⠐⡈⢿⣇⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⢠⣿⠋⠄⡂⠅⠡⢐⢀⠢⠐⡁⠌⡨⠐⡈⠔⡀⢿⣧⡡⢁⠢⠨⠨⢐⠠⠡⠠⢁⢂⠂⠅⡂⠅⡂⠌⡐⢸⣿⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⣿⡇⠌⡐⠠⡁⠅⡂⢂⠌⡐⠄⠅⡐⠨⠐⡐⢐⢈⠻⣷⣶⣬⣤⣕⠄⠌⡐⡁⡂⢢⣨⠐⡐⢐⠠⢁⠂⣵⣿⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⣿⡆⠅⠂⠅⢂⠡⢐⠐⡐⢐⠨⢐⠈⢌⣔⠠⠡⢐⢀⢂⢱⣿⢏⠻⣿⣶⣴⣴⣾⠿⠣⢁⢂⠡⠨⢐⣰⣿⠃⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⠸⣿⣌⠌⠨⢐⢈⢐⢈⢐⠐⠨⢀⢊⣾⣏⠂⠅⡂⠔⣐⣿⠏⡄⢵⣿⢋⠉⠅⠅⡡⢁⢂⠂⠌⠄⢷⣿⠁⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⢀⣾⠟⠨⢈⠄⡂⡐⡐⣶⣮⣬⣦⣿⠟⢿⣧⡡⢐⢐⣾⡟⠨⢰⣿⠏⠠⠊⠄⠅⢂⠂⡂⠌⠌⡐⠨⣿⡇⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⣼⡟⠨⢈⠄⡂⠔⡀⠢⠐⡉⡉⡙⢿⣮⡨⢻⣷⡔⣼⡿⠨⡘⣾⡯⠨⢈⢐⠡⠨⢐⢐⠠⢁⢊⠠⢁⢿⡇⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⢸⣯⡨⠐⡀⡂⠢⠨⢐⠡⢐⠠⠂⢌⢻⣷⡐⡹⣿⣿⡫⠨⣸⣿⠂⠅⢂⠂⢌⢐⢐⠠⠨⢐⠠⠨⣰⣿⠃⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⠀⠻⣷⣥⣂⢌⣂⣕⣶⣧⡂⡂⠅⡂⢂⢻⣷⡐⡙⢟⢐⠅⣿⡗⢈⠌⣰⣼⣶⣔⣐⡨⡨⣐⡈⠚⠟⠁⠀⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠻⠛⠋⠃⠙⠿⣾⣦⣮⣴⣼⣿⡇⢌⢂⠢⢊⣿⣧⣶⣷⠟⠋⠈⠙⠛⠻⠛⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠉⠉⠁⢽⡯⡂⢅⠪⢐⣿⡋⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢽⡯⡐⠔⡡⠡⣿⡅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⢏⠢⢑⢐⠅⣿⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡆⢅⠕⡐⠌⣿⡃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣺⡯⡂⡊⡄⢕⣿⡅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;
	tree1 = "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢺⣿⣾⣾⣾⣶⣿⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀";
	outfile << tree1 << std::endl;

	outfile.close();
	std::cout << filename << ": Output success" << std::endl;
}
