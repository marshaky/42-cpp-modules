/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:04:42 by marshaky          #+#    #+#             */
/*   Updated: 2026/08/02 19:05:42 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm( "PresidentialPardonForm", 25, 5 )
	, target("Default")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm( "PresidentialPardonForm", 25, 5 )
	, target( target )
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
	: AForm( src )
	, target(src.target)
{}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		target = rhs.target;
	}
	return *this;
}

void    PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if ( executor.getGrade() > this->getGradeToExecute() )
        throw AForm::GradeTooLowException();
    else
        std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}