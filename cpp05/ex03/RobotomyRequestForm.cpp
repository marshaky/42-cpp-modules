/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:04:51 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:04:52 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: Form("Robotomy Request Form", 72, 45)
	, target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
	: Form(src)
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
		throw Form::GradeTooLowException();
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