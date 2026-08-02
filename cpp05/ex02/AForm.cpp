/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:01:52 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:01:53 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	: name("NoName")
	, isSigned(false)
	, gradeToSign(0)
	, gradeToExecute(0)
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

std::ostream&	operator<<(std::ostream &os, AForm& AForm)
{
	os << "Name: " << AForm.getName() << "\n"
		   << "Signed: " << (AForm.getSigned() == true ? "yes" : "no") << "\n"
		   << "Grade to sign: " << AForm.getGradeToSign() << "\n"
		   << "Grade to execute: " << AForm.getGradeToExecute() << "\n" 
		   << std::endl;
	return os;
}
