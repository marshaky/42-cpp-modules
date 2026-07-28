/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:03:03 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:03:04 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class Form;

class RobotomyRequestForm : public Form
{
private:
    const std::string   target;

    RobotomyRequestForm();

public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& src);
    ~RobotomyRequestForm();

    RobotomyRequestForm &operator=(const RobotomyRequestForm& rhs);

    void        execute(const Bureaucrat& executor) const;
};

#endif