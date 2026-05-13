/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 23:44:34 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/14 03:20:25 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	private:
		std::string	_name;
	public:
		Zombie(std::string name);
		Zombie(void);
		~Zombie();
		void	announce(void);
		void	setName(std::string name);
};

	Zombie* zombieHorde(int N, std::string name);

#endif