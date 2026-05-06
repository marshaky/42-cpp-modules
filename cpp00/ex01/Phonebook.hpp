/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 00:43:05 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/07 00:43:11 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

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