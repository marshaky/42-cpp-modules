/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 19:50:53 by marshaky          #+#    #+#             */
/*   Updated: 2026/08/20 19:51:25 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cerr;
using std::endl;

void printHeader(const std::string& title)
{
    cout << "\n==========================================" << endl;
    cout << "   " << title << endl;
    cout << "==========================================" << endl;
}

int main(void)
{
    // Seed random number generator for Robotomy success rate
    std::srand(std::time(NULL));

    printHeader("1. BUREAUCRAT GRADE BOUNDARY TESTS");
    {
        try {
            Bureaucrat high("Overachiever", 0);
        } catch (std::exception& e) {
            cerr << "Expected Error (Grade 0): " << e.what() << endl;
        }

        try {
            Bureaucrat low("Slacker", 151);
        } catch (std::exception& e) {
            cerr << "Expected Error (Grade 151): " << e.what() << endl;
        }
    }

    printHeader("2. UNSIGNED FORM EXECUTION TESTS");
    {
        Bureaucrat boss("CEO", 1);
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        // Attempting execution WITHOUT signing first (Must throw NotSignedException)
        boss.executeForm(shrub);
        boss.executeForm(robot);
        boss.executeForm(pardon);
    }

    printHeader("3. SHRUBBERY CREATION FORM TEST");
    {
        Bureaucrat gardener("Gardener", 130);
        ShrubberyCreationForm shrub("garden");

        cout << shrub << endl;
        gardener.signForm(shrub);
        gardener.executeForm(shrub);
        cout << "Check working directory for 'garden_shrubbery' file." << endl;
    }

    printHeader("4. ROBOTOMY REQUEST FORM TEST (50% Chance)");
    {
        Bureaucrat surgeon("Doctor", 40);
        RobotomyRequestForm robot("Target Dummy");

        surgeon.signForm(robot);
        cout << "-- Executing 4 times to test randomness --" << endl;
        for (int i = 0; i < 4; ++i) {
            surgeon.executeForm(robot);
        }
    }

    printHeader("5. PRESIDENTIAL PARDON FORM TEST");
    {
        Bureaucrat president("Zaphod", 1);
        Bureaucrat intern("Lowly Intern", 150);
        PresidentialPardonForm pardon("Ford Prefect");

        intern.signForm(pardon); // Should fail (Grade 150 vs Grade 25 needed)
        president.signForm(pardon); // Should succeed

        intern.executeForm(pardon); // Should fail (Grade 150 vs Grade 5 needed)
        president.executeForm(pardon); // Should succeed
    }

    printHeader("6. INTERN FORM CREATION TESTS");
    {
        Intern someRandomIntern;
        AForm* rrf;
        AForm* scf;
        AForm* ppf;
        AForm* unknown;

        Bureaucrat boss("Ultimate Boss", 1);

        // Test valid creations
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        scf = someRandomIntern.makeForm("shrubbery creation", "Backyard");
        ppf = someRandomIntern.makeForm("presidential pardon", "Marvin");
        
        // Test invalid creation (Should print error and return NULL safely)
        unknown = someRandomIntern.makeForm("tax return request", "Company");

        cout << "\n-- Testing Intern-Created Forms --" << endl;
        if (rrf) {
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }

        if (scf) {
            boss.signForm(*scf);
            boss.executeForm(*scf);
            delete scf;
        }

        if (ppf) {
            boss.signForm(*ppf);
            boss.executeForm(*ppf);
            delete ppf;
        }

        if (unknown == NULL) {
            cout << "Invalid form gracefully returned NULL as expected." << endl;
        }
    }

    printHeader("ALL TESTS COMPLETED");
    return 0;
}