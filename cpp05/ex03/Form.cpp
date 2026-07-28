/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:03:42 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:03:43 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: name("NoName")
	, isSigned(false)
	, gradeToSign(0)
	, gradeToExecute(0)
{}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name)
	, isSigned(false)
	, gradeToSign(gradeToSign)
	, gradeToExecute(gradeToExecute)
{
	if (gradeToSign < HIGHEST_GRADE || gradeToExecute < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	if (gradeToSign > LOWEST_GRADE || gradeToExecute > LOWEST_GRADE)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& rhs)
	: name(rhs.name)
	, isSigned(rhs.isSigned)
	, gradeToSign(rhs.gradeToSign)
	, gradeToExecute(rhs.gradeToExecute)
{}

Form::~Form() {}

const std::string& Form::getName() const
{
	return name;
}

bool Form::getSigned() const
{
	return isSigned;
}

int Form::getGradeToSign() const
{
	return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->gradeToExecute;
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if ( bureaucrat.getGrade() > gradeToSign )
		throw Form::GradeTooLowException();
	isSigned = true;
}

std::ostream&	operator<<(std::ostream &os, Form& form)
{
	os << "Name: " << form.getName() << "\n"
		   << "Signed: " << (form.getSigned() == true ? "yes" : "no") << "\n"
		   << "Grade to sign: " << form.getGradeToSign() << "\n"
		   << "Grade to execute: " << form.getGradeToExecute() << "\n" 
		   << std::endl;
	return os;
}
