/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:04:07 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:04:08 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
    {
        Intern  someRandomIntern;
        Form*   rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        delete rrf;
        rrf = someRandomIntern.makeForm("shrubbery reques", "bender");
        delete rrf;
    }
}