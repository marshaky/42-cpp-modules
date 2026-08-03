/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 18:27:20 by marshaky          #+#    #+#             */
/*   Updated: 2026/08/03 18:27:22 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm {
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeToSign;
	const int			gradeToExecute;
public:
	AForm();
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& rhs);
	virtual ~AForm();
	AForm&	operator=( const AForm& rhs );
	const std::string&	getName() const;
	bool				getSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	void				beSigned(Bureaucrat& bureaucrat);
	virtual void		execute(const Bureaucrat& executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return "AForm exception: exception: grade too high!"; 
		}
    };
	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return "AForm exception: exception: grade too low!";
		}
	};
	class NotSignedException : public std::exception {
	public:
		const char *what() const throw() {
			return "AForm exception: exception: AForm not signed!";
		}
	};
};

std::ostream&	operator<<(std::ostream &os, AForm& AForm);

#endif