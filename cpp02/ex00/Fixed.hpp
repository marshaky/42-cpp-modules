/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:37:33 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/15 19:53:18 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
# define __FIXED_HPP__

# include <iostream>

class	Fixed
{
	private:
		int					_value;
		static const int	_fract;
	public:
		Fixed();
		Fixed(Fixed const &copy);
		~Fixed();
		
		Fixed &operator=(Fixed const &copy);
		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif