/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:17:45 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:17:46 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << BRED << "Error: could not open file."<< CRST << std::endl;
		return 1;
	}

	try {
		BitcoinExchange	ob;
		ob.databaseInit("data.csv");
		ob.exchangePrint(av[1]);
	} catch (std::exception& e) {
		std::cout << BRED "BitcoinExchange:" CRST \
			"exception caught: " << e.what() << std::endl; 
	}

	return 0;
}