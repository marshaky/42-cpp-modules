/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 03:55:59 by marshaky          #+#    #+#             */
/*   Updated: 2026/08/02 18:21:24 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class	Form {
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeToSign;
	const int			gradeToExecute;
public:
	Form();
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& rhs);
	~Form();
	Form&	operator=( const Form& rhs );
	const std::string&	getName() const;
	bool				getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	void				beSigned(Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return "Form exception: exception: grade too high!"; 
		}
    };
	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Form exception: exception: grade too low!";
		}
	};
	class NotSignedException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return "Form exception: exception: form not signed!";
		}
	};
};

std::ostream&	operator<<(std::ostream &os, Form& form);

#endif