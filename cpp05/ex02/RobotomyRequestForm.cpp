/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:03:00 by marshaky          #+#    #+#             */
/*   Updated: 2026/08/02 18:47:11 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request Form", 72, 45)
	, target("Default")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy Request Form", 72, 45)
	, target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
	: AForm(src)
	, target(src.target)
{}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&    RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	(void)rhs;
	return *this;
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if ( executor.getGrade() > this->getGradeToExecute() )
		throw AForm::GradeTooLowException();
	else
	{
		static int  i;
		if ( i % 2 == 0 )
			std::cout << "BZZZZZT! " << target << " has been robotomized!" << std::endl;
		else
			std::cout << "Robotomy failed! " << target << " is still alive." << std::endl;
		i++;
    }
}