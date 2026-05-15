/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:37:33 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/16 01:56:40 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					_value;
		static const int	_fract = 8;
	public:
		Fixed();
		Fixed(const int &value);
		Fixed(const float &value);
		Fixed(Fixed const &copy);
		~Fixed();
		
		Fixed &operator=(Fixed const &copy);
		
		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits() const;
		void	setRawBits(int const raw);

		/* comparison operators */
		bool			operator>(const Fixed &other) const;
		bool			operator<(const Fixed &other) const;
		bool			operator>=(const Fixed &other) const;
		bool			operator<=(const Fixed &other) const;
		bool			operator==(const Fixed &other) const;
		bool			operator!=(const Fixed &other) const;

		/* arithmetic operators */
		Fixed			operator+(const Fixed &other) const;
		Fixed			operator-(const Fixed &other) const;
		Fixed			operator*(const Fixed &other) const;
		Fixed			operator/(const Fixed &other) const;

		/* increment and decrement operators */
		Fixed			&operator++();
		Fixed			operator++(int);
		Fixed			operator--(int);
		Fixed			&operator--();

		/* static member functions */
		static			Fixed &min(Fixed &a, Fixed &b);
		static const	Fixed &min(const Fixed &a, const Fixed &b);
		static			Fixed &max(Fixed &a, Fixed &b);
		static const	Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif