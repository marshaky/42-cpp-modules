/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:04:01 by marshaky          #+#    #+#             */
/*   Updated: 2026/08/20 19:48:44 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
    typedef AForm* (Intern::*FormCreator)(const std::string& target);
    AForm* createRobotomy(const std::string& target);
    AForm* createShrubbery(const std::string& target);
    AForm* createPresidential(const std::string& target);
public:
    Intern();
    Intern(const Intern& src);
    ~Intern();
    Intern& operator=(const Intern& rhs);
    AForm* makeForm(std::string name, std::string target);
};

#endif