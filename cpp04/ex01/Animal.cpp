/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 19:13:05 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/22 23:58:12 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << this->_type << "object created" << std::endl;
}

Animal::Animal(const Animal& rhs)
{
	*this = rhs;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal	&Animal::operator=(const Animal& animal)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &animal)
		this->_type = animal._type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal makes a sound" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->_type);
}

Brain*	Animal::getBrain() const
{
	return (NULL);
}
