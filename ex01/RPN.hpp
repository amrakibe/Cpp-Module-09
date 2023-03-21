/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:00:42 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/21 15:06:58 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <sstream>

class	RPN
{
	private:
		std::string Reverse_Polish;
	public:
		RPN();
		RPN& operator=(const RPN& obj);
		RPN(const RPN& obj);
		RPN(std::string Reverse_Polish);
		~RPN();
};
void	RPNpolishedNotation(std::string Reverse_Polish);
void	ParseRpnPolishedNotation(std::string Reverse_Polish);
