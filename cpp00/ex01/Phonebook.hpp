/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 00:43:05 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/14 03:38:36 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

# include "Contact.hpp"

class Phonebook
{
private:
	Contact	contacts[8];
	int		idx;
public:
	Phonebook(void);
	~Phonebook(void);

	void	add(void);
	void	search(void);
	void	print(Contact contact);
	
	Contact	get_contact(int idx);
};

#endif