/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:15:52 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:15:53 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main()
{
	Array<int>	arr(5);

	for (size_t i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	Array<int> copy;
	copy = arr;

	for (size_t i = 0; i < copy.size(); ++i)
		std::cout << copy[i] << " ";
	std::cout << std::endl;

	for (size_t i = 0; i < copy.size(); ++i)
		copy[i] = i;

	for (size_t i = 0; i < copy.size(); ++i)
		std::cout << copy[i] << " ";
	std::cout << std::endl;

	copy[5] = 10;

}