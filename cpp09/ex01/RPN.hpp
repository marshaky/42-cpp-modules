/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:17:54 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:17:55 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# define BRED	"\033[1;31m"
# define BGRN	"\033[1;32m"
# define BYEL	"\033[1;33m"
# define BBLU	"\033[1;34m"
# define BWHT	"\033[1;37m"
# define CRST	"\033[0m"

# include <iostream>
# include <sstream>
# include <exception>
# include <stack>

class RPN {
	private:
		std::stack<int>	stack;

	public:
		RPN();
		RPN(const RPN& rhs);
		~RPN();

		RPN&	operator=(const RPN& rhs);

	public:
		int	calculate(std::string& expr);

	public:
		class DivisionByZeroExcept : public std::exception {
			public:
				const char*	what() const throw();
		};

		class IncompleteExprExcept : public std::exception {
			public:
				const char*	what() const throw();
		};

	private:
		bool	isValidExpression(const std::string& expr);
		int		ft_stoi(const std::string& str);
};

#endif