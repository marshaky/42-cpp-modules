/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 01:48:22 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/23 01:48:23 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	std::cout << "Cure created with default constructor" << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure destroyed" << std::endl;
}

Cure::Cure(Cure const &copy): AMateria(copy)
{
	std::cout << "Cure copied" << std::endl;
}

Cure const	&Cure::operator=(const Cure &copy)
{
	this->_type = copy._type;
	return (*this);
}

AMateria	*Cure::clone(void) const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
