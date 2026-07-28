/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:24:32 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/07 00:24:54 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("NoName")
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& bro) : name(bro.name), grade(bro.grade)
{
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& bro)
{
	if (this != &bro)
	{
		const_cast<std::string&>(this->name) = bro.name;
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
