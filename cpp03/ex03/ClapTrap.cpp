/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 00:35:51 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/19 19:11:07 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("default"), _hp(10), _energy_points(10), _damage(0)
{
	std::cout << "ClapTrap " << this->_name << " created with default constructor." << std::endl;
}

ClapTrap::ClapTrap(std::string const &name): _name(name), _hp(10), _energy_points(10), _damage(0)
{
	std::cout << "ClapTrap " << this->_name << " created." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " destroyed." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << "ClapTrap " << this->_name << " copied." << std::endl;
	*this = copy;
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->_energy_points && this->_hp > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacked " << target << ", causing " << this->_damage << " point(s) of damage!" << std::endl;
		this->_energy_points--;
	}
	if (this->_hp <= 0)
		std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
	else if (!this->_energy_points)
		std::cout << "ClapTrap " << this->_name << " is out of energy points!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp > 0)
	{
		std::cout << "ClapTrap " << this->_name << " took " << amount << " point(s) of damage!" << std::endl;
		this->_hp -= amount;
	}
	else
		std::cout << "STOP! ClapTrap " << this->_name << " is already dead :(" << std::endl;
	if (this->_hp < 0)
		this->_hp = 0;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp > 0 && this->_energy_points)
	{
		std::cout << "ClapTrap " << this->_name << " healed " << amount << " point(s)." << std::endl;
		this->_hp += amount;
		this->_energy_points--;
	}
	if (this->_hp <= 0)
		std::cout << "Cannot repair because: ClapTrap " << this->_name << " is dead." << std::endl;
	else if (!this->_energy_points)
		std::cout << "ClapTrap " << this->_name << " is out of energy points!" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "ClapTrap assignment operator called." << std::endl;
	this->_name = copy._name;
	this->_hp = copy._hp;
	this->_energy_points = copy._energy_points;
	this->_damage = copy._damage;
	return (*this);
}