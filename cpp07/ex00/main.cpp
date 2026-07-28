/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:14:55 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:14:56 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"
#include <string>

int main() {
    int a = 5, b = 10;
    std::cout << "Before swap - a: " << a << ", b: " << b << std::endl;
    swap(a, b);
    std::cout << "After swap - a: " << a << ", b: " << b << std::endl;

    int c = 15, d = 20;
    std::cout << "Min of c and d is: " << min(c, d) << std::endl;
    std::cout << "Max of c and d is: " << max(c, d) << std::endl;

    std::string str1 = "Hello", str2 = "World";
    std::cout << "Before swap - str1: " << str1 << ", str2: " << str2 << std::endl;
    swap(str1, str2);
    std::cout << "After swap - str1: " << str1 << ", str2: " << str2 << std::endl;

    std::string str3 = "Apple", str4 = "Banana";
    std::cout << "Min of str3 and str4 is: " << min(str3, str4) << std::endl;
    std::cout << "Max of str3 and str4 is: " << max(str3, str4) << std::endl;

    return 0;
}
