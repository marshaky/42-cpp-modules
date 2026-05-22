/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 20:33:27 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/23 01:41:21 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "DogCat.hpp"
#include "Wrong.hpp"

void	testSubject(void) {
	std::cout << "\n>>> RUNNING SUBJECT TESTS\n"  << std::endl;
	/* Subject asking to create and make an array with half Dog and half Cat */
	Animal	*animals[4];

	for (int i = 0; i < 4; i++) {
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	/* Testing destructors order (Brain > Dog/Cat > Animal) */
	std::cout << "Filling done. Deleting every Animal..."  << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i];

	/* Provided by subject */
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	delete j;
	delete i;
}

void	testDeepCopy(void) {
	std::cout << "\n>>> RUNNING DEEPCOPY TESTS\n" << std::endl;
	std::cout << "--- Dog's behavior ---" << std::endl;
	Dog	dogA;
	Dog dogB;

	std::cout << "-------" << std::endl;
	dogA.getBrain()->ideas[0] = "DogA's idea";
	dogB.getBrain()->ideas[0] = "DogB's idea";
	std::cout << "DogA's address (" << &dogA << ")..." << std::endl;
	std::cout << "    idea[0]=" << dogA.getBrain()->ideas[0] << " (" << &dogA.getBrain()->ideas[0] << ")" << std::endl;
	std::cout << "DogB's address (" << &dogB << ")..." << std::endl;
	std::cout << "    idea[0]="  << dogB.getBrain()->ideas[0] << " (" << &dogB.getBrain()->ideas[0] << ")" << std::endl;

	std::cout << "-------" << std::endl;
	dogB = dogA;
	std::cout << "DogA's address (" << &dogA << ")..." << std::endl;
	std::cout << "    idea[0]=" << dogA.getBrain()->ideas[0] << " (" << &dogA.getBrain()->ideas[0] << ")" << std::endl;
	std::cout << "DogB's address (" << &dogB << ")..." << std::endl;
	std::cout << "    idea[0]=" << dogB.getBrain()->ideas[0] << " (" << &dogB.getBrain()->ideas[0] << ")" << std::endl;

	std::cout << "--- Cat's behavior ---" << std::endl;
	Cat	catA;
	Cat catB;

	std::cout << "-------" <<  std::endl;
	catA.getBrain()->ideas[0] = "CatA's idea";
	catB.getBrain()->ideas[0] = "CatB's idea";
	std::cout << "CatA's address (" << &catA << ")..." << std::endl;
	std::cout << "    idea[0]=" << catA.getBrain()->ideas[0] << " (" << &catA.getBrain()->ideas[0] << ")" << std::endl;
	std::cout << "CatB's address (" << &catB << ")..." << std::endl;
	std::cout << "    idea[0]=" << catB.getBrain()->ideas[0] << " (" << &catB.getBrain()->ideas[0] << ")" << std::endl;

	std::cout << "-------"  << std::endl;
	catB = catA;
	std::cout << "CatA's address (" << &catA << ")..." << std::endl;
	std::cout << "    idea[0]=" << catA.getBrain()->ideas[0] <<  " (" << &catA.getBrain()->ideas[0] << ")" << std::endl;
	std::cout << "CatB's address (" << &catB << ")..." << std::endl;
	std::cout << "    idea[0]=" <<  catB.getBrain()->ideas[0] << " (" << &catB.getBrain()->ideas[0] << ")" << std::endl;
}

int	main(void) {
	testSubject();
	testDeepCopy();
	
	// Tests are done
	std::cout << "All tests completed."  << std::endl;
	return (0);
}