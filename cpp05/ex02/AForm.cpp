/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:27:11 by marshaky          #+#    #+#             */
/*   Updated: 2026/08/19 19:44:16 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
        : name("NoName")
        , isSigned(false)
        , gradeToSign(150)
        , gradeToExecute(150)
{}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name)
	, isSigned(false)
	, gradeToSign(gradeToSign)
	, gradeToExecute(gradeToExecute)
{
	if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& rhs)
	: name(rhs.name)
	, isSigned(rhs.isSigned)
	, gradeToSign(rhs.gradeToSign)
	, gradeToExecute(rhs.gradeToExecute)
{}

AForm &AForm::operator=( const AForm& rhs )
{
	if (this != &rhs)
	{
		isSigned = rhs.isSigned;
	}
	return (*this);
}

AForm::~AForm() {}

const std::string& AForm::getName() const
{
	return name;
}

bool AForm::getSigned() const
{
	return isSigned;
}

int AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if ( bureaucrat.getGrade() > gradeToSign )
		throw AForm::GradeTooLowException();
	isSigned = true;
}

std::ostream&	operator<<(std::ostream &os, const AForm& AForm)
{
	os << "Name: " << AForm.getName() << "\n"
		   << "Signed: " << (AForm.getSigned() == true ? "yes" : "no") << "\n"
		   << "Grade to sign: " << AForm.getGradeToSign() << "\n"
		   << "Grade to execute: " << AForm.getGradeToExecute() << "\n" 
		   << std::endl;
	return os;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm exception: grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm exception: grade too low!";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "AForm exception: AForm not signed!";
}
