/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 00:35:47 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/19 02:15:40 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CLAPTRAP_HPP__
# define __CLAPTRAP_HPP__

# include <iostream>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hp;
		int			_energy_points;
		int			_damage;
	public:
		ClapTrap(void);
		ClapTrap(std::string const &name);
		ClapTrap(ClapTrap const &copy);
		~ClapTrap(void);
		
		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		ClapTrap	&operator=(ClapTrap const &copy);
};

#endif