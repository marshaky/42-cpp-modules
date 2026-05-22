/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 01:51:00 by marshaky          #+#    #+#             */
/*   Updated: 2026/05/23 01:51:34 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MATERIASOURCE_HPP__
# define __MATERIASOURCE_HPP__

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria	*_learnInventory[4];

		int 				inLearnInventory(AMateria *materia);

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &copy);
		~MateriaSource(void);

		MateriaSource const	&operator=(MateriaSource const &copy);

		virtual void		learnMateria(AMateria *materia);
		virtual AMateria*	createMateria(std::string const &type);
};

#endif