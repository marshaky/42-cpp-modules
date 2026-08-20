/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 03:56:12 by marshaky          #+#    #+#             */
/*   Updated: 2026/08/03 19:12:25 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <cstdlib>

using std::cout;
using std::cerr;
using std::endl;

int main(void)
{
    cout << "=== GENERAL & CANONICAL FORM ===" << endl;
    {
        Form    a("Contract", 42, 42);
        Form    b(a);
        Form    c = b;

        cout << "a:\n" << a << endl;
        cout << "b:\n" << b << endl;
        cout << "c:\n" << c << endl;
    }

    cout << "\n=== EXCEPTION TESTS (CONSTRUCTION) ===" << endl;
    {
        cout << "-- Test 1: Grade too low --" << endl;
        try {
            Form a("A", LOWEST_GRADE + 1, LOWEST_GRADE);
            cout << a << endl;
        } catch (std::exception& e) {
            cerr << e.what() << endl;
        }

        cout << "\n-- Test 2: Grade too high --" << endl;
        try {
            Form b("B", HIGHEST_GRADE - 1, 42);
            cout << b << endl;
        } catch (std::exception& e) {
            cerr << e.what() << endl;
        }
    }

    cout << "\n=== DIRECT beSigned() TESTS ===" << endl;
    {
        try {
            Bureaucrat  boss("Boss", HIGHEST_GRADE);
            Bureaucrat  intern("Intern", LOWEST_GRADE);
            Form        topSecret("Top Secret", 10, 5);

            cout << topSecret << endl;

            // Direct signing fail
            try {
                topSecret.beSigned(intern);
            } catch (std::exception& e) {
                cerr << "Direct sign failed: " << e.what() << endl;
            }

            // Direct signing success
            topSecret.beSigned(boss);
            cout << "Signed status: " << (topSecret.getSigned() ? "Signed" : "Not Signed") << endl;
        } catch (std::exception& e) {
            cerr << e.what() << endl;
        }
    }

    cout << "\n=== BUREAUCRAT signForm() TESTS ===" << endl;
    {
        Bureaucrat  highGrade("Alice", 5);
        Bureaucrat  lowGrade("Bob", 140);
        Form        taxForm("Tax Form", 50, 20);

        cout << taxForm << endl;

        cout << "-- Failed attempt via signForm --" << endl;
        lowGrade.signForm(taxForm); // Should print failure message internally

        cout << "\n-- Successful attempt via signForm --" << endl;
        highGrade.signForm(taxForm); // Should print success message internally

        cout << "\nFinal state:\n" << taxForm << endl;
    }

    return 0;
}