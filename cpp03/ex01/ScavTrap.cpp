/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 22:59:55 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/19 19:09:34 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default")
{
    this->_hp = 100;
    this->_energy_points = 50;
    this->_damage = 20;
	std::cout << "ScavTrap " << this->_name << " created with default constructor." << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
    this->_hp = 100;
    this->_energy_points = 50;
    this->_damage = 20;
    std::cout << "ScavTrap " << this->_name << " created." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " destroyed." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy): ClapTrap(copy)
{
	std::cout << "ScavTrap " << this->_name << " copied." << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &copy)
{
	std::cout << "ScavTrap assignment operator called." << std::endl;
	ClapTrap::operator=(copy);
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	if (this->_hp <= 0)
		std::cout << "Cannot switch to gate-keeper mode because: ClapTrap " << this->_name << " is dead." << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " switched to mode: \"Guard Gate\"." << std::endl;
}

void	ScavTrap::attack(std::string const &target)
{
	if (this->_energy_points && this->_hp > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacked " << target << ", causing " << this->_damage << " point(s) of damage!" << std::endl;
		this->_energy_points--;
	}
	if (this->_hp <= 0)
		std::cout << "ScavTrap " << this->_name << " is dead!" << std::endl;
	else if (!this->_energy_points)
		std::cout << "ScavTrap " << this->_name << " is out of energy points!" << std::endl;
}