/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 00:35:49 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/19 18:42:23 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap("TP");

    clap.attack("Bandit");
    clap.takeDamage(5);
    clap.beRepaired(3);
    clap.takeDamage(15);
    clap.beRepaired(10);
    clap.attack("Skag");
    clap.takeDamage(20);
    clap.attack("Spiderant");
    clap.takeDamage(10);
    clap.attack("Rakk");
    clap.takeDamage(8);
    clap.beRepaired(15);
    clap.attack("Badass Psycho");
    clap.takeDamage(30);
    clap.attack("Badass Bruiser");
    clap.takeDamage(25);

    return 0;
}