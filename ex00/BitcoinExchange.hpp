/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:31 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/26 02:19:39 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>

class BitcoinExchange
{
	private:
		float value;
		std::string date;
		std::map<std::string, double> _data;
		std::list<std::string> sp;
	public:
		BitcoinExchange(std::string nameFile = "data.csv");
		BitcoinExchange(const BitcoinExchange &bit_obj);
		BitcoinExchange&operator=(const BitcoinExchange &bit_obj);
		void ParseBitcoin(char **av);
		~BitcoinExchange();
		std::list<std::string> ft_split(std::string length, char delimiter);
		bool bitcoinExchange(std::list<std::string> a);
};

std::string	trim(std::string str);
bool 		ParseDate(int y, int m, int d);
bool 		checkIsValidValue(std::string sp);
bool 		checkDashInDate(std::string date);
bool 		checkValidDate(int y, int m, int d);