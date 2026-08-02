/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:04:51 by marshaky          #+#    #+#             */
/*   Updated: 2026/08/02 19:05:54 by marshaky         ###   ########.fr       */
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
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		target = rhs.target;
	}
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