/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marshaky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 04:17:51 by marshaky          #+#    #+#             */
/*   Updated: 2026/07/28 04:17:52 by marshaky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& rhs)
{
	*this = rhs;
}

RPN::~RPN() {}

RPN&	RPN::operator=(const RPN& rhs)
{
	this->stack = rhs.stack;
	return (*this);
}

const char*	RPN::DivisionByZeroExcept::what() const throw()
{
	return ("Division by zero is impossible");
}

const char*	RPN::IncompleteExprExcept::what() const throw()
{
	return ("Invalid expression");
}

int	RPN::ft_stoi(const std::string& str)
{
	int					num;
	std::stringstream	ss(str);

	ss >> num;
	return num;
}

bool	RPN::isValidExpression(const std::string& expr)
{
	int	n = 0;
	int	op = 0;

	for (size_t i = 0; i < expr.size(); ++i)
	{
		if (expr.at(i) == ' ')
			continue ;

		bool	is_n = std::isdigit(expr.at(i));
		bool	is_op = (expr.at(i) == '+' || expr.at(i) == '-' \
						|| expr.at(i) == '*' || expr.at(i) == '/');

		if (is_op) ++op;
		else if (is_n) ++n;
		else
			return (false);
	}
	return (op = n - 1);
}

int	RPN::calculate(std::string& expr)
{
	if (!isValidExpression(expr))
		throw IncompleteExprExcept();

	int	res;

	for(size_t i = 0; i < expr.size(); ++i)
	{
		if (expr.at(i) == ' ')
			continue ;

		bool	is_n = std::isdigit(expr.at(i));
		bool	is_op = (expr.at(i) == '+' || expr.at(i) == '-' \
						|| expr.at(i) == '*' || expr.at(i) == '/');

		if (is_op)
		{
			if (stack.size() < 2)
				throw IncompleteExprExcept();
			
			int	right = stack.top();
			stack.pop();
			int left = stack.top();
			stack.pop();

			switch(expr.at(i))
			{
				case '+':
					res = left + right;
					break ;
				case '-':
					res = left - right;
					break ;
				case '*':
					res = left * right;
					break ;
				case '/':
					if (right == 0)
						throw DivisionByZeroExcept();
					res = left / right;
					break ;
			}
			stack.push(res);
		}
		else if (is_n)
		{
			int num = ft_stoi(&expr.at(i));

			if(num > 9)
				throw IncompleteExprExcept();
			stack.push(num);
		}
	}
	res = stack.top();
	return res;
}

