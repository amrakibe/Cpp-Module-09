/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:00:42 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/26 13:39:19 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <sstream>

void	RPNpolishedNotation(std::string Reverse_Polish);
void	ParseRpnPolishedNotation(std::string Reverse_Polish);
void	checkVNumber(std::string str);
