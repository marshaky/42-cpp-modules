/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:17:23 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:17:24 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

// int main()
// {
//     Span sp(5);
    
//     sp.addNumber(10);
//     sp.addNumber(20);
//     sp.addNumber(30);
//     sp.addNumber(40);
//     sp.addNumber(50);

//     /* capacity check */
//     // try
//     // {
//     //     sp.addNumber(60);
//     // }
//     // catch (const std::exception &e)
//     // {
//     //     std::cout << "Exception caught: " << e.what() << std::endl;
//     // }

//     std::vector<int> numbers;
// 	numbers.push_back(1);
// 	numbers.push_back(2);
// 	numbers.push_back(3);
// 	numbers.push_back(4);
// 	numbers.push_back(5);

// 	Span sp1(5);
//     sp1.addNumber(numbers.begin(), numbers.end());


//     int shortest = sp.shortestSpan();
//     int longest = sp.longestSpan();

//     std::cout << "Shortest span: " << shortest << std::endl;
//     std::cout << "Longest span: " << longest << std::endl;

//     return 0;
// }


int main()
{
    const size_t numNumbers = 10000;
    Span sp(numNumbers);

    // Generate random numbers
    std::vector<int> numbers(numNumbers);
    std::srand(std::time(0));
    for (size_t i = 0; i < numNumbers; ++i)
    {
        numbers[i] = std::rand() % 1000 + 1;
    }

    // Add numbers to Span
    std::cout << "Adding " << numNumbers << " numbers..." << std::endl;
    sp.addNumber(numbers.begin(), numbers.end());

    // Calculate and display shortest and longest spans
    std::cout << "Calculating spans..." << std::endl;
    int shortest = sp.shortestSpan();
    int longest = sp.longestSpan();

    std::cout << "Shortest span: " << shortest << std::endl;
    std::cout << "Longest span: " << longest << std::endl;

    return 0;
}


