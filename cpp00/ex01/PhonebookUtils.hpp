/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhonebookUtils.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 00:44:16 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/07 00:44:23 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTUTILS_H
# define CONTACTUTILS_H

# include "Contact.hpp"

std::string	add_spaces(int n);
std::string	str_resize(std::string str, unsigned long max);
int			contact_list(Contact contacts[8]);

#endif