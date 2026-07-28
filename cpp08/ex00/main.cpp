/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:17:19 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:17:21 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"
#include <vector>

int	main()
{
	std::vector<int> vec;

	vec.push_back(17);
	vec.push_back(8);
	vec.push_back(19);
	vec.push_back(4);
	vec.push_back(9);

	std::cout << "\nTEST 1" << std::endl;
	try {
		std::vector<int>::iterator it = easyfind(vec, 4);
		std::cout << *it << std::endl;
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\nTEST 2" << std::endl;
	try{
		std::vector<int>::iterator it = easyfind(vec, 7);
		std::cout << *it << std::endl;
	} catch(std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;

}