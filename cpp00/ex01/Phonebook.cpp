/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 00:43:44 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/07 00:48:50 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "PhonebookUtils.hpp"

Phonebook::Phonebook(void)
{
	this->idx = 0;
	std::cout << "\nWelcome! A phonebook for up to 8 contacts is created." << std::endl;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Bye." << std::endl;
}

Contact	Phonebook::get_contact(int idx)
{
	return (this->contacts[idx % 8]);
}

void	Phonebook::add(void)
{
	std::string	str = "";
	
	str = "";
	if (this->idx > 7)
		std::cout << "Warning: overwriting the information about " << this->contacts[idx % 8].get_fname() << std::endl;
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter the first name: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts[idx % 8].set_fname(str); 
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->contacts[idx % 8].get_fname() << "'s last name: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts[idx % 8].set_lname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->contacts[this->idx % 8].get_fname() << "'s nickname: "; 
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->idx % 8].set_nick(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->contacts[this->idx % 8].get_fname() << "'s phone number: ";
		if (std::getline(std::cin, str) && str != "")
			this->contacts[this->idx % 8].set_phone_num(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->contacts[this->idx % 8].get_fname() << "'s darkest secret: ";
		if (std::getline(std::cin, str) && str != "")
		{
			this->contacts[this->idx % 8].set_secret(str);
			std::cout << this->contacts[this->idx % 8].get_fname() << " successfully added to phonebook [" << this->idx % 8 + 1 << "/8]" << std::endl;
		}
	}
	this->idx++;
}

void	Phonebook::search(void)
{
	std::string	str;

	if (!contact_list(this->contacts))
	{
		std::cout << std::endl << "Phonebook is empty!" << std::endl;
		return ;
	}
	while (!std::cin.eof())
	{
		std::cout << "Select an index: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && \
					this->contacts[str[0] - 1 - '0'].get_fname().size())
				break ;
		}
		if (str != "")
			std::cout << "Invalid index!" << std::endl;
	}
	if (!std::cin.eof())
		this->print(this->contacts[str[0] - 1 - '0']);
}

void	Phonebook::print(Contact contact)
{
	std::cout << std::endl << "Requesting contact information..." << std::endl;
	if (!contact.get_fname().size())
	{
		std::cout << "Failed to get info for this contact" << std::endl;
		return ;
	}
	std::cout << "First Name: " << contact.get_fname() << std::endl;
	std::cout << "Last Name: " << contact.get_lname() << std::endl;
	std::cout << "Nickname: " << contact.get_nick() << std::endl;
	std::cout << "Phone Number: " << contact.get_phone_num() << std::endl;
	std::cout << "Darkest Secret: " << contact.get_secret() << std::endl;
}