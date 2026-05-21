/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 02:24:09 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/19 19:19:55 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("default_clap_name")
{
	this->_name = "default";
	this->_hp = 100;
	this->_energy_points = 50;
	this->_damage = 30;
	std::cout << "DiamondTrap " << this->_name << " created with default constructor." << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->_hp = FragTrap::_hp;
	this->_energy_points = ScavTrap::_energy_points;
	this->_damage = FragTrap::_damage;
	std::cout << "DiamondTrap " << this->_name << " created." << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_name << " destroyed." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	this->_name = copy._name;
	*this = copy;
	std::cout << "DiamondTrap " << this->_name << " copied." << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &copy)
{
	std::cout << "DiamondTrap assignment operator called." << std::endl;
	ScavTrap::operator=(copy);
	FragTrap::operator=(copy);
	this->_name = copy._name;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	if (this->_hp <= 0)
		std::cout << "Cannot run whoAmI because: DiamondTrap " << this->_name << " is dead." << std::endl;
	else
	{
		std::cout << "DiamondTrap name: " << this->_name << "." << std::endl;
		std::cout << "ClapTrap name: " << this->ClapTrap::_name << "." << std::endl;
	}
}

void	DiamondTrap::attack(std::string const &target)
{
	ScavTrap::attack(target);
}