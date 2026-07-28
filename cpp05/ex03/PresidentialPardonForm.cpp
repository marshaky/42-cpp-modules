/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:04:42 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:04:43 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: Form( "PresidentialPardonForm", 25, 5 )
	, target( target )
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
	: Form( src )
	, target(src.target)
{}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	(void)rhs;
	return *this;
}

void    PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if ( executor.getGrade() > this->getGradeToExecute() )
        throw Form::GradeTooLowException();
    else
        std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}