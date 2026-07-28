/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:02:14 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:02:15 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{

    try {
        Bureaucrat bureaucrat("Bro", 2);
        ShrubberyCreationForm form1("Shrubbery");
        RobotomyRequestForm form2("Robotomy");
        PresidentialPardonForm form3("President");

        std::cout << "\n--------------- Form 1 ( Shrubbery ) ---------------" << std::endl;
        bureaucrat.signForm(form1);
        bureaucrat.execute(form1);
        std::cout << "\n--------------- Form 2 ( Robotomy ) ---------------" << std::endl;
        bureaucrat.signForm(form2);
        bureaucrat.execute(form2);
        bureaucrat.execute(form2);
        bureaucrat.execute(form2);
        bureaucrat.execute(form2);
        std::cout << "\n--------------- Form 3 ( President ) ---------------" << std::endl;
        bureaucrat.signForm(form3);
        bureaucrat.execute(form3);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}