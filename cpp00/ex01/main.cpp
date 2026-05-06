/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 00:45:09 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/07 00:45:15 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main(void)
{
	Phonebook	pb;
	std::string	str;

	std::cout << "Command List" << std::endl;
	std::cout << "\tADD:\tsave a new contact" << std::endl;
	std::cout << "\tSEARCH:\tdisplay a specific contact" << std::endl;
	std::cout << "\tEXIT" << std::endl;
	while (str != "EXIT")
	{	
		std::cout << "\nEnter a command > ";
		std::getline(std::cin, str);
		if (str == "ADD")
			pb.add();
		else if(str == "SEARCH")
			pb.search();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return(0);
		}
	}
	return (0);
}