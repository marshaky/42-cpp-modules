/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 00:35:49 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/19 02:22:53 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    {
        ScavTrap scav("SC4V-TP");

        scav.guardGate();
        scav.attack("Bandit");
        scav.takeDamage(30);
        scav.beRepaired(15);
        scav.attack("Skag");
    }
    
    {
        ClapTrap *clap = new ScavTrap("SC4V-TP");

        clap->attack("Bandit");
        clap->takeDamage(30);
        clap->beRepaired(15);
        clap->attack("Skag");

        delete clap;
    }

    return 0;
}