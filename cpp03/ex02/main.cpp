/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 00:35:49 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/19 02:22:47 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    return 0;
}