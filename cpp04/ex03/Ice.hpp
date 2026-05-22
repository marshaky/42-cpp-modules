/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 01:49:18 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/23 01:49:36 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ICE_HPP__
# define __ICE_HPP__

#include "ICharacter.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(Ice const &copy);
		~Ice(void);

		Ice const	&operator=(Ice const &copy);

		AMateria*	clone(void) const;
		void		use(ICharacter &target);
};

#endif