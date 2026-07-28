/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:16:31 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:16:32 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <string>

int main(void)
{

	std::cout << "__________________\n" << std::endl;

	std::string str[3] = {
		"I-E-A-I-A-I-O",
		"why?",
		"And we light up the sky"
	};
	iter(str, 3, blabla);

	std::cout << "__________________\n" << std::endl;

	return (0);
}