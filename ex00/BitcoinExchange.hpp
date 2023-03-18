/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:31 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/18 22:32:32 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define MIN -18446744073709551615UL
#include <iostream>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iomanip>
#include <sstream>
class BitcoinExchange
{
	private:
		float value;
		std::string data;
	public:
		BitcoinExchange(float value, std::string data);
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &bit_obj);
		BitcoinExchange&operator=(const BitcoinExchange &bit_obj);
		void test(char **av);
		std::string trim(std::string t);
		~BitcoinExchange();
		std::list<std::string> ft_split(std::string length, char delimiter);
};
