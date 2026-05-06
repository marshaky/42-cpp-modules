/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhonebookUtils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 00:44:42 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/07 00:44:53 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

std::string	add_spaces(int n)
{
	std::string	str;

	while(n--)
		str.append(" ");
	return (str);
}

std::string	str_resize(std::string str, unsigned long max)
{
	if (str.size() > max)
	{
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	return (str);
}

int	contact_list(Contact contacts[8])
{
	std::string	str;
	int			i;

	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	
	i = -1;
	while (++i < 8 && contacts[i].get_fname().size())
	{
		str = i + 1 +'0';
		str = str_resize(str, 10);
		std::cout << "|" << add_spaces(10 - str.size()) << str;
		str = str_resize(contacts[i].get_fname(), 10);
		std::cout << "|" << add_spaces(10 - str.size()) << str;
		str = str_resize(contacts[i].get_lname(), 10);
		std::cout << "|" << add_spaces(10 - str.size()) << str;
		str = str_resize(contacts[i].get_nick(), 10);
		std::cout << "|" << add_spaces(10 - str.size()) << str;
		std::cout << "|" << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
	return (i);
}