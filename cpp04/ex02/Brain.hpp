/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 23:49:53 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/22 23:50:42 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BRAIN_HPP
# define __BRAIN_HPP

#include <iostream>

class Brain {
	public:
		std::string	ideas[100];

		Brain();
		Brain(const Brain& brain);
		~Brain();
		Brain&	operator=(const Brain& brain);
};

#endif