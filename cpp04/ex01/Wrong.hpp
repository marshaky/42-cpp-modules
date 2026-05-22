/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrong.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:19:31 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/22 20:24:08 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WRONG_HPP__
# define __WRONG_HPP__

#include <iostream>

class WrongAnimal {

	protected:
		std::string	_type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &wrongAnimal);
		~WrongAnimal();
		WrongAnimal	&operator=(const WrongAnimal &wrongAnimal);
		
		void	makeSound() const;
		std::string	getType() const;
};

class WrongCat : public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat &wrongCat);
		~WrongCat();
		WrongCat	&operator=(const WrongCat &wrongCat);
		
		void	makeSound() const;
};

#endif