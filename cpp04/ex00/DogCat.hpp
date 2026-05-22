/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DogCat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:07:35 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/22 20:16:57 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __DOGCAT_HPP__
# define __DOGCAT_HPP__

#include "Animal.hpp"

class Dog : public Animal {
	public:
		Dog();
		Dog(const Dog &dog);
		~Dog();
		Dog	&operator=(const Dog &dog);
		
		virtual void	makeSound() const;
};

class Cat : public Animal {
	public:
		Cat();
		Cat(const Cat &cat);
		~Cat();
		Cat	&operator=(const Cat &cat);

		virtual void	makeSound() const;
};

#endif