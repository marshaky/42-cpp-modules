/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 02:19:04 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/19 19:12:16 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("default")
{
	this->_hp = 100;
	this->_energy_points = 100;
	this->_damage = 30;
	
	std::cout << "FragTrap " << this->_name << " created with default constructor." << std::endl;
}

FragTrap::FragTrap(std::string const &name): ClapTrap(name)
{
	this->_hp = 100;
	this->_energy_points = 100;
	this->_damage = 30;
	
	std::cout << "FragTrap " << this->_name << " created." << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " destroyed." << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy): ClapTrap(copy)
{
	*this = copy;
	std::cout << "FragTrap " << this->_name << " copied." << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &copy)
{
	std::cout << "FragTrap assignment operator called." << std::endl;
	ClapTrap::operator=(copy);
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (this->_hp <= 0)
		std::cout << "Cannot high five because: ClapTrap " << this->_name << " is dead." << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " says: \"HIGH FIVE EVERYONE! :)\"." << std::endl;
}