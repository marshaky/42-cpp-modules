/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:37:31 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/16 01:32:27 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fract = 8;

Fixed::Fixed()
{
	this->_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

/* 1234 << 8 = 1234 * 256 = 1234 * 2^8 = 1234 * 256 = 123400 */
Fixed::Fixed(const int &value)
{
	this->_value = value << _fract;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float &value)
{
	this->_value = roundf(value * (1 << _fract));
	std::cout << "Float constructor called" << std::endl; 
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
	if (this != &copy)
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

float	Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _fract));
}

int	Fixed::toInt(void) const
{
	return (_value >> _fract);
}

std::ostream &operator<<(std::ostream &str, const Fixed &fixed_nbr)
{
	return (str << fixed_nbr.toFloat());
}
