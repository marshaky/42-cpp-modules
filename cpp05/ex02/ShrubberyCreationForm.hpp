/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:03:08 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:03:09 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form {
private:
	const std::string	target;

	ShrubberyCreationForm();

public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
	~ShrubberyCreationForm();

	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& rhs);

	void	execute(const Bureaucrat& executor) const;
};

#endif