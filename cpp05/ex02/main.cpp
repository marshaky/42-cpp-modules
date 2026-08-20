/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:02:14 by marshaky          #+#    #+#             */
/*   Updated: 2026/08/20 19:43:32 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
    std::srand(std::time(NULL));

    std::cout << "========== EX02 TESTS ==========" << std::endl;

    Bureaucrat boss("Boss", 2);
    Bureaucrat middle("Middle", 50);
    Bureaucrat intern("Intern", 150);

    /*
     * ============================
     * SHRUBBERY
     * ============================
     */
    std::cout << "\n--- ShrubberyCreationForm ---" << std::endl;

    ShrubberyCreationForm shrubbery("home");

    intern.signForm(shrubbery);
    boss.signForm(shrubbery);

    middle.executeForm(shrubbery);
    boss.executeForm(shrubbery);

    /*
     * ============================
     * ROBOTOMY
     * ============================
     */
    std::cout << "\n--- RobotomyRequestForm ---" << std::endl;

    RobotomyRequestForm robotomy("Bender");

    middle.signForm(robotomy);
    middle.executeForm(robotomy);
    middle.executeForm(robotomy);
    middle.executeForm(robotomy);
    middle.executeForm(robotomy);

    /*
     * ============================
     * PRESIDENTIAL
     * ============================
     */
    std::cout << "\n--- PresidentialPardonForm ---" << std::endl;

    PresidentialPardonForm pardon("Arthur Dent");

    middle.signForm(pardon);
    boss.signForm(pardon);

    middle.executeForm(pardon);
    boss.executeForm(pardon);

    /*
     * ============================
     * UNSIGNED FORM
     * ============================
     */
    std::cout << "\n--- Unsigned form execution ---" << std::endl;

    ShrubberyCreationForm unsignedForm("unsigned");

    boss.executeForm(unsignedForm);

    /*
     * ============================
     * EXECUTION GRADE FAILURE
     * ============================
     */
    std::cout << "\n--- Execution grade failure ---" << std::endl;

    PresidentialPardonForm secondPardon("Ford Prefect");

    boss.signForm(secondPardon);
    middle.executeForm(secondPardon);

    return 0;
}