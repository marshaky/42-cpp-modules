/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:01:54 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:02:08 by marshaky         ###   ########.fr       */
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
	Form();
public:
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& rhs);
	virtual ~Form();
	Form&	operator=( const Form& rhs );
	const std::string&	getName() const;
	bool				getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	void				beSigned(Bureaucrat& bureaucrat);
	virtual void		execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return "Form exception: exception: grade too high!"; 
		}
    };
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return "Form exception: exception: grade too low!";
		}
	};
	class NotSignedException : public std::exception {
	public:
		const char *what() const throw() {
			return "Form exception: exception: form not signed!";
		}
	};
};

std::ostream&	operator<<(std::ostream &os, Form& form);

#endif