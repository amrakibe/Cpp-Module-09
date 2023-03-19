/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:28 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/19 16:56:16 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// std::cout << "BitcoinExchange Default constructor called" << std::endl;
	this->date = "";
	this->value = 0;
}

BitcoinExchange::BitcoinExchange(float value, std::string date)
{
	// std::cout << "BitcoinExchange constructor " << std::endl;
	this->value = value;
	this->date = date;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	// std::cout << "BitcoinExchange Copy constructor called" << std::endl;
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	// std::cout << "BitcoinExchange Copy assignment operator called" << std::endl;
	this->date = obj.date;
	this->value = obj.value;
	return (*this);
}
BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "BitcoinExchange Destructor called" << std::endl;
}

void ParseDate(std::string date, int i)
{
	// (void)date;
	//  years
	if(i == 0)
	{
		// if((int)std::atof(date) % 4 != 0) 
			std::cout << "hhh: " << i << " " <<"< "<< date << " > " <<std::endl;
	}

	//  mounth

	if (i == 1)
	{
		std::cout << "hhh: " << i << " " <<"< "<< date << " >" <<std::endl;
	}

	// day
	if (i == 2)
	{
		std::cout << "hhh: " << i << " " <<"< "<< date << " >" <<std::endl;
		// std::cout << "hhh" << i << std::endl;
	}
	// std::cout << date<< std::endl;
	// for (size_t i = 0; i < date.size(); i++)
	// {
	// 	if (date[i] != 3)
	// 	{
	// 		std::cerr << "Error: bad input " << date[i] << std::endl;
	// 	}
	// 	if (!isdigit(date[i]))
	// 	{
	// 		std::cerr << "The input was not a valid integer: " << date[i] << std::endl;
	// 		return;
	// 	}
	// }
	// std::cout << "this is front: " << date.front() << std::endl;
}

void BitcoinExchange::test(char **av)
{
	BitcoinExchange ex;
	std::string name = av[1];
	std::ifstream inp_file(name);
	std::string out;
	if (!inp_file.is_open())
	{
		std::cerr << "Error : could not open file." << std::endl;
	}
	else
	{
		while (std::getline(inp_file, out))
		{
			std::list<std::string> sp = ex.ft_split(out, '|');

			if (sp.size() != 2)
			{
				std::cerr << "Error: bad input " << sp.front() << std::endl;
				continue;
			}
			sp.front() = trim(sp.front());
			sp.back() = trim(sp.back());
			double value = static_cast<double>(atof(sp.back().c_str()));
			for (size_t i = 0; i < sp.back().size(); i++)
			{
				if (sp.back()[i] == '.')
					i++;
				if (!isdigit(sp.back()[i]))
				{
					std::cerr << "The input was not a valid integer: " << sp.back() << std::endl;
					return;
				}
			}
			if (value < 0 || value > 1000)
			{
				std::cerr << (value > 1000 ? " Error: number is large " : "Error: not a positive number.") << std::endl;
				continue;
			}
			std::list<std::string> a = ex.ft_split(sp.front(), '-');
			if (a.size() != 3)
					std::cout << "error:" << std::endl;
			std::list<std::string>::iterator it = a.begin();
			int i = 0;
			for (; it != a.end(); it++)
			{
				ParseDate(*it, i++);
				// std::cout << "it : " << *it << std::endl;
			}
		}
	}
}

std::string BitcoinExchange::trim(std::string t)
{
	std::string afterTrim;

	size_t i = t.find_first_not_of(" \t");
	if (i != std::string::npos)
		afterTrim = t.substr(i);
	i = afterTrim.find_last_not_of(" \t");
	if (i != std::string::npos)
		afterTrim = afterTrim.substr(0, i + 1);
	return (afterTrim);
}

std::list<std::string> BitcoinExchange::ft_split(std::string length, char delimiter)
{
	std::list<std::string> list;

	std::string sub_string;
	std::stringstream input_file(length);
	while (std::getline(input_file, sub_string, delimiter))
		if (sub_string != "")
			list.push_back(sub_string);
	return list;
}
