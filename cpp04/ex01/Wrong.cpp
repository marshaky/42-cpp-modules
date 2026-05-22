/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:21:43 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/22 20:33:18 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Wrong.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << this->_type << "object created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal) : _type(wrongAnimal._type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& wrongAnimal)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &wrongAnimal)
    {
        _type = wrongAnimal._type;
    }
    return *this;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes a sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal(wrongCat)
{
	 std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	 std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& wrongCat)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
    if (this != &wrongCat)
    {
        WrongAnimal::operator=(wrongCat);
    }
    return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "Meow - Meow" << std::endl;
}
