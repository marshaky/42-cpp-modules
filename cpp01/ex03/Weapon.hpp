/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 03:34:36 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/14 03:39:23 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WEAPON_HPP__
# define __WEAPON_HPP__

# include <iostream>

class	Weapon
{
	private:
		std::string	_type;
	public:
		Weapon(std::string type);
		~Weapon();
		void	setType(std::string type);
		const	std::string	&getType(void);
};

#endif