/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 03:55:43 by marshaky          #+#    #+#             */
/*   Updated: 2026/08/02 18:26:00 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("NoName"), isSigned(false), gradeToSign(0), gradeToExecute(0)
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

Form &Form::operator=( const Form& rhs )
{
	if (this != &rhs)
	{
		isSigned = rhs.isSigned;
	}
	return (*this);
}

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