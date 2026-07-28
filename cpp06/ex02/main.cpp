/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:12:58 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:12:59 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"

int	main()
{
	Base*	bptr = new(B);
	C*		cptr = new(C);
	Base*	unknown = generate();


	identify(bptr);
	identify(cptr);
	identify(unknown);

	delete bptr;
	delete cptr;
	delete unknown;
}