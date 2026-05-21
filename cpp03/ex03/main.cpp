/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 00:35:49 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/19 20:11:13 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    {
        FragTrap frag("FR4G-TP");

        frag.highFivesGuys();
        frag.attack("Bandit");
        frag.takeDamage(30);
        frag.beRepaired(20);
        frag.attack("Skag");
    }

    {
        ClapTrap *clap = new FragTrap("FR4G-TP");

        clap->attack("Bandit");
        clap->takeDamage(30);
        clap->beRepaired(20);
        clap->attack("Skag");

        delete clap;
    }
    DiamondTrap d;
d.attack("s");
    return 0;
}