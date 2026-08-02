/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marshaky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 00:23:40 by marshaky          #+#    #+#             */
/*   Updated: 2026/08/02 18:07:04 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class	Bureaucrat {
private:
	const std::string	name;
	int					grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& bro);
	Bureaucrat&	operator=(const Bureaucrat& bro);
	~Bureaucrat();
	const std::string&	getName() const;
	int					getGrade() const;
	void				setGrade(int grade);
	void				incrementGrade();
	void				decrementGrade();

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