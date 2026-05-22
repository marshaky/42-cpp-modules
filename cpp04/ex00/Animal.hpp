/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 19:11:33 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/22 20:20:48 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ANIMAL_HPP__
# define __ANIMAL_HPP__

#include <iostream>
#include <string>

class Animal {

	protected:
		std::string	_type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& rhs);
		virtual ~Animal(void);
		Animal	&operator=(const Animal &animal);
		
		virtual void	makeSound() const;
		std::string	getType() const;
};

#endif