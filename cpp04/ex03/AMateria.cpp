/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 01:46:15 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/23 01:46:17 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	this->_type = "unidentified";
}

AMateria::AMateria(std::string const &type): _type(type)
{
	std::cout << "AMateria object created" << std::endl;
}

AMateria::AMateria(AMateria const &copy)
{
	*this = copy;
	std::cout << "AMateria object copied" << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria object destroyed" << std::endl;
}

AMateria const	&AMateria::operator=(AMateria const &copy)
{
	this->_type = copy._type;
	std::cout << "AMateria Assignment Operator Called" << std::endl;
	return (*this);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "* undefined materia thrown at " << target.getName() << " *" << std::endl;
}

std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}
