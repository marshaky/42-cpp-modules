/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:17:59 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:18:00 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& rhs) { (void)rhs; }

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs){ (void)rhs; return (*this); }

PmergeMe::PmergeMe(int ac, char** av)
{
	operator()(ac, av);
}

const char* PmergeMe::NotEnoughArgsException::what() const throw()
{
	return ("Too few arguments for sorting");
}

const char*	PmergeMe::InvalidNumberException::what() const throw()
{
	return ("Invalid number detected");
}

bool	PmergeMe::isValidInput(int ac, char** av)
{

	for (int i = 1; i < ac; ++i)
	{
		for (size_t j = 0; j < std::strlen(av[i]); ++j)
		{
			bool space = 0;

			if (av[i][j] == ' ')
			{
				++j;
				space = 1;
			}
			if (!std::isdigit(av[i][j]))
				return false; 
			if ((space || j == 0) && std::atoi(&av[i][j]) <= 0)
				return false;
		}
	}
	return true;
}

void	PmergeMe::operator()(int ac, char** av)
{
	if (ac < 3)
		throw NotEnoughArgsException();
	if (!isValidInput(ac, av))
		throw InvalidNumberException();

	for (int i = 1; i < ac; ++i)
	{
		std::istringstream iss(av[i]);
		int num;
		while (iss >> num)
		{
			vec.push_back(num);
			deq.push_back(num);
		}
	}

	std::cout << std::endl;

	_print(BYEL "Before: " CRST, vec);
	_start(vec, vecTime);
	_start(deq, deqTime);
	_print(BBLU "After: " CRST, vec);

	std::cout << std::endl;
	std::cout << "Time to process a range of " << vec.size() \
		<< " elements with std::vector : " BGRN \
		<< std::fixed << std::setprecision(5) << vecTime<< " us" CRST \
		<< std::endl;
	std::cout << "Time to process a range of " << vec.size() \
		<< " elements with std::deque : " BGRN \
		<< std::fixed << std::setprecision(5) << deqTime << " us" CRST \
		<< std::endl;
	std::cout << BYEL "Are containers sorted?" CRST << std::endl;
	std::cout << "std::vector [ " << (_isSorted(vec) ? BGRN "YES" : BRED "NO") \
		<< CRST " ]" << std::endl;
	std::cout << "std::deque [ " << (_isSorted(deq) ? BGRN "YES" : BRED "NO") \
		<< CRST " ]" << std::endl;
	
}