/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:00:39 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/20 22:07:28 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::~RPN(){}

RPN::RPN(){this->Reverse_Polish = "";}

RPN::RPN(const RPN &obj){*this = obj;}

RPN &RPN::operator=(const RPN &obj)
{
    if (this != &obj) 
    {
        this->Reverse_Polish = obj.Reverse_Polish;
    }
    return (*this);
}

RPN::RPN(std::string Reverse_Polish) {this->Reverse_Polish = Reverse_Polish;}

void	ParseRpnPolishedNotation(std::string Reverse_Polish)
{
	// std::cout << "Reverse Polish Notation : [ " << Reverse_Polish << " ]" << std::endl;
	if(Reverse_Polish.length() == 0)
	{
		std::cerr << "Error: empty input" << std::endl;
		exit(1);
	}
	for (size_t i = 0; i < Reverse_Polish.length(); i++)
	{
		if(Reverse_Polish[i] == '+' || Reverse_Polish[i] == '-' || Reverse_Polish[i] == '*' || Reverse_Polish[i] == '/')
			continue;
		if(!std::isdigit(Reverse_Polish[i]))
		{
			std::cerr << "Error : invalid input." << std::endl;
			exit(1);
		}
		if(Reverse_Polish[i] < 0 || Reverse_Polish[i + 1] > 0)
		{
			std::cerr << "Error : hhhhhhhhhh" << std::endl;
			exit(1);
		}
	}
    RPNpolishedNotation(Reverse_Polish);
}

void	RPNpolishedNotation(std::string Reverse_Polish)
{
	std::stack<int> stack;
	// std::cout << "this is s : " << stack.top() << std::endl;
	for (size_t i = 0; i < Reverse_Polish.length(); i++)
    {
		char c = Reverse_Polish[i];
		if(std::isdigit(Reverse_Polish[i]))
		{
		    stack.push(c - 48);
		}
		else
		{
			if (stack.size() == 0)
			{
				std::cerr << "Error 2" << std::endl;
				exit(1);
			}
			int b = stack.top(); stack.pop();
			if (stack.size() == 0)
			{
				std::cerr << "Error 1" << std::endl;
				exit(1);
			}
			int a = stack.top(); stack.pop();
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
					stack.push(a / b);
					break;
            }
    	}
	}
	std::cout << "stack top : [" << stack.top()<<"]" << std::endl;
}
