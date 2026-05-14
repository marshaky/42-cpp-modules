/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 03:59:30 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/14 04:01:58 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	replace(char **argv, std::string str)
{
	std::ofstream	outfile;
	int				pos;

	outfile.open((std::string(argv[1]) + ".new").c_str());
	if (outfile.fail())
	{
		std::cout << "Error: couldn't create the outfile" << std::endl;
		return (1);
	}
	for (int i = 0; i < (int)str.size(); i++)
	{
		pos = str.find(argv[2], i);
		if (pos != (int)std::string::npos && pos == i)
		{
			outfile << argv[3];
			i += std::string(argv[2]).size() - 1;
		}
		else
			outfile << str[i];
	}
	outfile.close();
	return (0);
}

int	main(int argc, char **argv)
{
	std::ifstream	infile;
	std::string		str;
	char			c;

	if (argc != 4)
	{
		std::cout << "usage: replace <file> <old_str> <new_str>" << std::endl;
		return (1);
	}
	infile.open(argv[1]);
	if (infile.fail())
	{
		std::cout << "Error: " << argv[1] << ":" << " no such file or directory" << std::endl;
		return (1);
	}
	while (!infile.eof() && infile >> std::noskipws >> c)
		str += c;
	infile.close();
	replace(argv, str);
}