/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:28 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/30 02:42:00 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string nameFile)
{
	std::ifstream inp_file(nameFile);
	std::string out;
	std::string buff2;
	std::string buff1;

	if (!inp_file.is_open())
		std::cout << "Error : could not open file." << std::endl;
	else
	{
		std::getline(inp_file, out);
		while (std::getline(inp_file, out))
		{
			std::stringstream str(out);
			if (out.empty())
			{
				std::cout << "Error: file is empty" << std::endl;
				exit(1);
			}
			std::getline(str, buff1, ',');
			std::getline(str, buff2, ',');
			// !! insert  key  and value to map
			data[buff1] = std::atof(buff2.c_str());
			// std::cout << "value: " << buff2 << std::endl;
		}
			// std::cout << "date: " << data[] << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	*this = obj;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	if (this != &obj)
	{
		this->date = obj.date;
		this->value = obj.value;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

bool checkDashInDate(std::string date)
{
	for (size_t i = 0; i < date.size(); i++)
	{
		if(date[4] != '-' && date[7] != '-')
			return (std::cout << "Error: not a valid date => " << std::endl, false);
		if(i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
		{
			std::cout << "The input was not a valid integer: " << std::endl;
			continue;
		}
	}
	return (true);
}

bool checkIsValidValue(std::string sp)
{
	for (size_t i = 0; i < sp.size(); i++)
	{
		if (sp[i] == '.')
			continue;
		if (!std::isdigit(sp[i]))
			return (std::cout << "Error: not a valid date " << sp << std::endl, false);
	}
	if (sp.find(".") != sp.rfind("."))
		return (std::cout << "Error: not a valid number " << sp << std::endl, false);
	return (sp.back() == '.' ? std::cout << "Error: not a valid date" << std::endl, false : true);
}

bool ParseDate(int y, int m, int d)
{
	bool leaps = false;

	if (y % 4 == 0)
		leaps = true;
	switch (m)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (d > 31)
		{
			std::cout << "Error: not a valid date" << std::endl;
			return (false);
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (d > 30)
		{
			std::cout << "Error not a valid date" << std::endl;
			return (false);
		}
		break;
	case 2:
		if (leaps)
		{
			if (d > 28)
			{
				std::cout << "Error: not a valid date" << std::endl;
				return (false);
			}
		}
		else
		{
			if (d > 29)
			{
				std::cout << "Error: not a valid date" << std::endl;
				return (false);
			}
		}
	}
	return (true);
}

void BitcoinExchange::ParseBitcoin(char **av)
{
	std::string name = av[1];
	std::ifstream inp_file(name);
	std::string out;

	if (inp_file.is_open())
	{
		if (inp_file.peek() == std::ifstream::traits_type::eof())
		{
			std::cout << "Error: file is empty" << std::endl;
			exit(1);
		}
		std::getline(inp_file, out);
		if(strcmp("date | value", out.c_str()) != 0)
		{
			std::cout << "Error: file is not valid" << std::endl;
			exit(1);
		}
		while (std::getline(inp_file, out))
		{
			if (out.find("|") != out.rfind("|"))
			{
				std::cout << "Error: bad input => " << out << std::endl;
				continue;
			}

			sp = ft_split(out, '|');
			sp.front() = trim(sp.front());
			sp.back() = trim(sp.back());

			if (sp.size() != 2)
			{
				std::cout << "Error: bad input => " << sp.front() << std::endl;
				continue;
			}
			if (sp.front().size() != 10 || !checkDashInDate(sp.front()))
			{
				std::cout << "Error: bad input => " << sp.front() << std::endl;
				continue;
			}
			value = (double)std::atof(sp.back().c_str());
			if (value < 0 || value > 1000)
			{
				std::cout << (value > 1000 ? "Error: too large a number " : "Error: not a positive number") << std::endl;
				continue;
			}
			if (!checkIsValidValue(sp.back()))
				continue;
			sp_date = ft_split(sp.front(), '-');
			if (sp_date.size() != 3)
			{
				std::cout << "Error: not a valid date => " << sp.front() << std::endl;
				continue;
			}
			if (bitcoinExchange(sp_date))
				continue;
		}
	}
	else
		std::cout << "Error : could not open file" << std::endl;
}

bool BitcoinExchange::bitcoinExchange(std::list<std::string> list)
{
	std::list<std::string>::iterator it = list.begin();
	int y = (int)std::atof((*it).c_str());
	int m = (int)std::atof((*++it).c_str());
	int d = (int)std::atof((*++it).c_str());

	if (!ParseDate(y, m, d))
		return (true);

	if (data.find(sp.front()) != data.end())
		std::cout << sp.front() << " => " << sp.back() << " = " << data[sp.front()] * value << std::endl;	
	else
	{
		std::map<std::string, double>::iterator it = data.lower_bound(sp.front());
		if (it == data.begin())
			return true;
		it--;
		std::cout << sp.front() << " => " << sp.back() << " = " << it->second * value << std::endl;
	}
	return (false);
}

std::string trim(std::string str)
{
	std::string afterTrim;

	size_t i = str.find_first_not_of(" \t");
	if (i != std::string::npos)
		afterTrim = str.substr(i);
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
	return (list);
}
