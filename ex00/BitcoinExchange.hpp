/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:31 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/23 20:53:39 by amrakibe         ###   ########.fr       */
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
		void test(char **av);
		// void test2(char **arr);
		// void func();
		std::string trim(std::string t);
		~BitcoinExchange();
		std::list<std::string> ft_split(std::string length, char delimiter);
};
std::string ft_it(std::string length, char delimiter);
void ParseDate(std::string date, int i);