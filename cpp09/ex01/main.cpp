/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:17:49 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:17:50 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char** av)
{
	if (ac == 2)
	{
		try {
			RPN	rpn;
			std::string	expr = av[1];
			std::cout << rpn.calculate(expr) << std::endl;
		} catch (std::exception& e) {
			std::cout << BRED "[ Exception caught ]\t" << CRST \
				<< e.what() << std::endl; 
		}
	}
	else
		std::cout << BRED "Error: " CRST \
		"usage: ./RPN <expression>" << std::endl;

	return 0;
}