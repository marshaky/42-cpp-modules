/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:04:01 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:04:05 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

enum Forms {
	ROBOTOMY = 'r',
	SHRUBBERY = 's',
	PRESIDENTIAL = 'p'
};

class Intern {
public:
    Intern();
    Intern(const Intern& src);
    ~Intern();
    Intern& operator=(const Intern& rhs);
    Form*   makeForm(std::string name, std::string target);
};

#endif