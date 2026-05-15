/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:37:33 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/16 01:22:53 by marshaky         ###   ########.fr       */
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
		static const int	_fract;
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
};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif