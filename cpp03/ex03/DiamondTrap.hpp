/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 02:24:13 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/19 02:26:45 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __DIAMONDTRAP_HPP__
# define __DIAMONDTRAP_HPP__

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string const &name);
		DiamondTrap(DiamondTrap const &copy);
		virtual ~DiamondTrap(void);

		DiamondTrap	&operator=(DiamondTrap const &copy);

		void	whoAmI(void);
		void	attack(std::string const &target);
};

#endif