/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 03:23:45 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/14 03:24:20 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int	size = 7;
	Zombie	*horde = zombieHorde(size, "Zomb");

	for (int i = 0; i < size; i++)
		horde[i].announce();
	delete [] horde;
}