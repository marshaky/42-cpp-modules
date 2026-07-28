/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:02:58 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:02:59 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
    std::string	target;

    PresidentialPardonForm();

public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& src);
    ~PresidentialPardonForm();

    PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
    
    void execute(const Bureaucrat& executor) const;
};

#endif 