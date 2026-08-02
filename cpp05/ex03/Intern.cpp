/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:03:58 by marshaky          #+#    #+#             */
/*   Updated: 2026/08/02 19:14:19 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& src)
{
	*this = src;
}

Intern::~Intern() {}

Intern&	Intern::operator=(const Intern& rhs)
{
	( void ) rhs;
	return (*this);
}

AForm*   Intern::makeForm( std::string name, std::string target )
{
	char	key;

	std::string formNames[] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};

	for (int i = 0; i < 3; ++i)
	{
		if (!name.compare(formNames[i]))
			key = name[0];
	}

	switch (key)
	{
	case ROBOTOMY:
		std::cout << "Intern creates " << name << std::endl;
		return new RobotomyRequestForm(target);
	case SHRUBBERY:
		std::cout << "Intern creates " << name << std::endl;
		return new ShrubberyCreationForm(target);
	case PRESIDENTIAL:
		std::cout << "Intern creates " << name << std::endl;
		return new PresidentialPardonForm(target);
	default:
		std::cout << "Intern cannot create " << name << " form" << std::endl;
		return NULL;
	}
	return NULL;
}