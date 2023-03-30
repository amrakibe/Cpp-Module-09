/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:00:42 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/30 01:53:53 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
#include <iostream>
#include <sstream>
#include <stack>

void	RPNpolishedNotation(std::string Reverse_Polish);
void	ParseRpnPolishedNotation(std::string Reverse_Polish);
void	checkVNumber(std::string str);
#endif