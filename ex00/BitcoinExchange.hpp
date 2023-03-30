/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:31 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/30 00:41:43 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

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
		std::map<std::string, double> data;
		std::list<std::string> sp;
		std::list<std::string> sp_date;
	public:
		BitcoinExchange(std::string nameFile = "data.csv");
		BitcoinExchange(const BitcoinExchange &bit_obj);
		BitcoinExchange&operator=(const BitcoinExchange &bit_obj);
		~BitcoinExchange();
		std::list<std::string> ft_split(std::string length, char delimiter);
		void ParseBitcoin(char **av);
		bool bitcoinExchange(std::list<std::string> list);
};

std::string	trim(std::string str);
bool 		ParseDate(int y, int m, int d);
bool 		checkIsValidValue(std::string sp);
bool 		checkDashInDate(std::string date);
#endif