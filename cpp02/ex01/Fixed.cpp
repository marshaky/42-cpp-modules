/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:37:31 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/16 19:51:31 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fract = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

/* 1234 << 8 = 1234 * 256 = 1234 * 2^8 = 1234 * 256 = 123400 */
Fixed::Fixed(const int &value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << _fract;
}

Fixed::Fixed(const float &value)
{
	std::cout << "Float constructor called" << std::endl; 
	this->_value = roundf(value * (1 << _fract));
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_value = copy.getRawBits();
	return (*this);
}
	
int	Fixed::getRawBits() const
{
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
