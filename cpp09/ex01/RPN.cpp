/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:02:06 by wscherre          #+#    #+#             */
/*   Updated: 2025/12/20 16:25:01 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN &src)
{
	(void)src;
}

RPN &RPN::operator=(const RPN &rhs)
{
	(void)rhs;
	return (*this);
}

RPN::~RPN()
{
}

void RPN::evaluate(const std::string &expression)
{
	long	val2;
	long	val1;

	std::stack<long> stack;
	std::stringstream ss(expression);
	std::string token;
	while (ss >> token)
	{
		if (token.length() == 1 && (token == "+" || token == "-" || token == "*"
				|| token == "/"))
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return ;
			}
			val2 = stack.top();
			stack.pop();
			val1 = stack.top();
			stack.pop();
			if (token == "+")
				stack.push(val1 + val2);
			else if (token == "-")
				stack.push(val1 - val2);
			else if (token == "*")
				stack.push(val1 * val2);
			else if (token == "/")
			{
				if (val2 == 0)
				{
					std::cerr << "Error: Division by zero." << std::endl;
					return ;
				}
				stack.push(val1 / val2);
			}
		}
		else if (token.length() == 1 && isdigit(token[0]))
			stack.push(token[0] - '0');
		else
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
	}
	if (stack.size() != 1)
		std::cerr << "Error" << std::endl;
	else
		std::cout << stack.top() << std::endl;
}
