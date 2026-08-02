/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:01:27 by marshaky          #+#    #+#             */
/*   Updated: 2026/08/02 18:45:17 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>
# include "AForm.hpp"
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class AForm;

class	Bureaucrat {
private:
	const std::string	name;
	int					grade;
	Bureaucrat();
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& bro);
	Bureaucrat&	operator=(const Bureaucrat& bro);
	~Bureaucrat();
	const std::string&	getName() const;
	int					getGrade() const;
	void				setGrade(int grade);
	void				incrementGrade();
	void				decrementGrade();
	// void 				signForm(std::string form_name, bool was_signed) const;
	void				signForm(AForm& form);
	void				execute(const AForm& form) const;

	class	GradeTooHighException : public std::exception {
		public:
			const char*	what() const throw();
	};
	class	GradeTooLowException : public std::exception {
		public:
			const char*	what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat &bro);

#endif