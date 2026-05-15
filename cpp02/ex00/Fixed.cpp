/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:37:31 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/16 01:23:53 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fract = 8;

Fixed::Fixed()
{
	this->_value = 0;
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
	std::cout << "Copy constructor called" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed &Fixed::operator=(Fixed const &copy)
{
	this->_value = copy.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}
		
int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}
void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}