/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    FragTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 02:19:06 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/19 02:21:03 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
# define __FRAGTRAP_HPP__

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &copy);
		~FragTrap(void);

		FragTrap	&operator=(FragTrap const &copy);

		void	highFivesGuys(void);
};

#endif