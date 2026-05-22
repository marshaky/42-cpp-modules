/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 01:48:26 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/23 01:48:49 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CURE_HPP__
# define __CURE_HPP__

#include "ICharacter.hpp"

class Cure: public AMateria
{
	public:
		Cure(void);
		Cure(Cure const &copy);
		~Cure(void);

		Cure const	&operator=(Cure const &copy);

		AMateria*	clone(void) const;
		void		use(ICharacter &target);
};

#endif