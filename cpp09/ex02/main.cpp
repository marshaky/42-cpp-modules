/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:17:57 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:17:58 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char** av)
{
	try {
		PmergeMe sort(ac, av);
	} catch(const std::exception& e) {
		std::cout << BRED "[ Exception caght ]" CRST \
			<< e.what() << std::endl;
	}
}