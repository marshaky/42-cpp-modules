/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhonebookUtils.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 00:44:16 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/14 03:38:48 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTACTUTILS_H__
# define __CONTACTUTILS_H__

# include "Contact.hpp"

std::string	add_spaces(int n);
std::string	str_resize(std::string str, unsigned long max);
int			contact_list(Contact contacts[8]);

#endif