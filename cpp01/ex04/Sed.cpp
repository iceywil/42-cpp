/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 00:13:05 by a                 #+#    #+#             */
/*   Updated: 2025/03/27 00:20:44 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void	replace(std::string infilename, std::string s1, std::string s2)
{
	std::string		outfilename = infilename + ".replace";
	std::ofstream	outf(outfilename.c_str());
	std::ifstream	infile(infilename.c_str());
	
	if (s1 == ""){
		std::cout << "Error" << std::endl << "S1 is empty" << std::endl;
		return ;
	}
	if (!infile.is_open())
		std::cerr << "Failed to open infile -> " << infilename << std::endl;
	if (!outf.is_open())
		std::cerr << "Failed to open outfile" << std::endl;

	std::string	line;
	if (std::getline(infile, line, '\0'))
	{
		size_t	pos = line.find(s1);
		while (pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos = line.find(s1);
		}
		outf << line;
		outf.close();
		infile.close();
	}
	else
		std::cout << infilename << " is empty." << std::endl;
}