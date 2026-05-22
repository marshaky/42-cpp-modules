/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DogCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:08:56 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/23 00:03:36 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DogCat.hpp"

Dog::Dog() : Animal("Dog")
{
	this->_brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog(const Dog &dog) : Animal(dog)
{
	*this = dog;
	std::cout << "Dog copy constructor called" << std::endl;
}
Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}
Dog& Dog::operator=(const Dog &dog)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &dog)
    {
        Animal::operator=(dog);
    }
    return *this;
}
		
void	Dog::makeSound() const
{
	std::cout << "Haf - Haf" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return (this->_brain);
}

Cat::Cat() : Animal("Cat")
{
	this->_brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
	*this = cat;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}
Cat& Cat::operator=(const Cat &cat)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &cat)
    {
        Animal::operator=(cat);
    }
    return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meow - Meow" << std::endl;
}

Brain*	Cat::getBrain() const
{
	return (this->_brain);
}