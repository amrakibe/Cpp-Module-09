/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:00:39 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/30 20:50:01 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void ParseRpnPolishedNotation(std::string Reverse_Polish)
{
	std::string line, str;
	std::stringstream a(Reverse_Polish);
	while (std::getline(a, line, ' '))
	{
		if (line == "+" || line == "-" || line == "*" || line == "/")
		{
			str += line;
			continue;
		}
		else
		{
			if (std::atof(line.c_str()) < 0 || std::atof(line.c_str()) > 9)
			{
				if(std::atof(line.c_str()) < 0 ? std::cout << "Error: not a positive number." << std::endl : \
					std::cout << "Error: too large a number" << std::endl)
				exit(1);
			}
			else
				str += line;
		}
	}
	checkVNumber(str);
}

void checkVNumber(std::string str)
{
	int lentOp = 0, lentNb = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			lentOp++;
			continue;
		}
		if (!isdigit(str[i]))
		{
			std::cout << "Error" << std::endl;
			exit(1);
		}
		else
			lentNb++;
	}
	if (lentOp != lentNb - 1)
	{
		std::cout << "Error: The result is Invalid (:" << std::endl;
		exit(1);
	}
	RPNpolishedNotation(str);
}

void RPNpolishedNotation(std::string Reverse_Polish)
{
	std::stack<int> stack;
	for (size_t i = 0; i < Reverse_Polish.length(); i++)
	{
		int a, b;
		char c = Reverse_Polish[i];
		if (std::isdigit(Reverse_Polish[i]))
		{
			stack.push(c - 48);
		}
		else
		{
			if (stack.size() == 0)
			{
				std::cout << "Error: stack A is empty (:" << std::endl;
				exit(1);
			}
			b = stack.top(); stack.pop();
			if (stack.size() == 0)
			{
				std::cout << "Error: stack B is empty (:" << std::endl;
				exit(1);
			}
			a = stack.top(); stack.pop();
		}
		switch (c)
		{
			case '+':
				stack.push(a + b);
				break;
			case '-':
				stack.push(a - b);
				break;
			case '*':
				stack.push(a * b);
				break;
			case '/':
				if (b == 0)
				{
					std::cout << "Error: Division By Zero (:" << std::endl;
					exit(1);
				}
				stack.push(a / b);
				break;
		}
	}
	std::cout << stack.top() << std::endl;
}
