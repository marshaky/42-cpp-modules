/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:33:27 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/22 23:56:50 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "DogCat.hpp"
#include "Wrong.hpp"

int main() {
    std::cout << "Creating and filling array of Animal objects..." << std::endl;
    Animal* animals[4];

    for (int i = 0; i < 4; i++) {
        if (i < 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "Deleting every Animal..." << std::endl;
    for (int i = 0; i < 4; i++)
        delete animals[i];

    std::cout << "Creating and deleting Dog and Cat objects..." << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;
    delete i;

    std::cout << "All tests completed." << std::endl;
    return 0;
}
