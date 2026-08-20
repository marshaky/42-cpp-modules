/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:01:12 by marshaky          #+#    #+#             */
/*   Updated: 2026/08/20 19:42:58 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("NoName"), grade(LOWEST_GRADE)
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bro)
	: name(bro.name)
	, grade(bro.grade)
{}

Bureaucrat::~Bureaucrat() {}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& bro)
{
	if (this != &bro)
	{
		//const_cast<std::string&>(this->name) = bro.name;
		this->grade = bro.grade;
	}
	return *this;
}

const std::string&	Bureaucrat::getName() const
{
	return this->name;
}

int	Bureaucrat::getGrade() const
{
	return this->grade;
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = grade;
}

void Bureaucrat::incrementGrade()
{
	if (grade - 1 < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	if (grade + 1 > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade += 1;
}

// void Bureaucrat::signForm(std::string formName, bool isSigned) const
// {
// 	if (isSigned)
// 		std::cout << this->getName() << " signed " << formName << std::endl;
// 	else
// 		std::cout << this->getName() << " couldn't sign " << formName
// 			 << " because the grade was too low" << std::endl;
// }

void	Bureaucrat::signForm(AForm& form)
{
	try {
		form.beSigned(*this);
		std::cout << *this << " signed " << form.getName() << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	try {
		form.execute( *this );
		std::cout << name << " executed " << form.getName() << std::endl;
	} catch ( std::exception& e ) {
		std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat exception: grade too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat exception: grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bro)
{
	os << bro.getName() << ", bureaucrat grade " << bro.getGrade();
	return os;
}
