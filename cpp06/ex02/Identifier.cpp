/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:12:56 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:12:57 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"

Base*	generate()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int	key = 1 + (std::rand() % 3);

	switch (key)
	{
		case 1:
			return new(A);
		case 2:
			return new(B);
		case 3:
			return new(C);
	}
	
	return NULL;
}

void	identify(Base* p)
{
	std::string	type[4] = {"A", "B", "C", "Base"};
	
	Base*	derived[4] = {
		dynamic_cast<A *>(p),
		dynamic_cast<B *>(p),
		dynamic_cast<C *>(p),
		dynamic_cast<Base *>(p)
	};

	int	i = 0;
	for (; i < 4 && !derived[i]; ++i) ;
	std::cout << "Actual type of pointer is: " << type[i] << std::endl;
}

void	identify(Base& p)
{
	std::string	type[4] = {"A", "B", "C", "Base"};
	
	Base*	derived[4] = {
		dynamic_cast<A *>(&p),
		dynamic_cast<B *>(&p),
		dynamic_cast<C *>(&p),
		dynamic_cast<Base *>(&p)
	};

	int	i = 0;
	for (; i < 4 && !derived[i]; ++i) ;
	std::cout << "Actual type of pointer is: " << type[i] << std::endl;
}
