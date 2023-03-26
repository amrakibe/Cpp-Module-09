/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:28 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/26 01:58:50 by amrakibe         ###   ########.fr       */
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
		std::cerr << "Error : could not open file." << std::endl;
	else
	{
		std::getline(inp_file, out);
		while (std::getline(inp_file, out))
		{
			std::stringstream str(out);
			std::getline(str, buff1, ',');
			std::getline(str, buff2, ',');
			// !! insert  key (data) and value to map
			_data[buff1] = std::atof(buff2.c_str());
		}
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

bool test(int y, int m, int d)
{
	if (std::to_string(y).length() != 4 || std::to_string(m).length() != 2 || std::to_string(d).length() != 2)
		return (false);
	return (true);
}

bool checkDashInDate(std::string date)
{
	int count = 0;
	for (size_t i = 0 ; i < date.size();i++)
	{
		if (date[i] == '-')
			count++;
		if (date[i] == '-' && date[i + 1] == '-')
			return (std::cerr << "Error: not a valid date => " << date << std::endl,false);
	}
	return (count != 2 ?std::cerr << "Error: not a valid date => " << date << std::endl ,false : true);
}

bool checkIsValidValue(std::string sp)
{
	for (size_t i = 0; i < sp.size(); i++)
	{
		if (sp[i] == '.')
			continue;
		if (!isdigit(sp[i]))
			return(std::cerr << "Error: not a valid date " << sp << std::endl ,false);
	}
	
	if (sp.find(".") != sp.rfind("."))
			return (std::cerr << "Error: not a valid number " << sp << std::endl,false);
			
	return (sp.back() == '.' ? std::cerr << "Error: not a valid date hhh" << std::endl ,false : true);
}

bool ParseDate(int y, int m, int d)
{

	bool leaps = false;

	if (test(y, m, d))
		return (std::cerr << "Error : date not valid " << std::endl, false);

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
			std::cerr << "Error: not a valid date " << std::endl;
			return (false);
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (d > 30)
		{
			std::cerr << "Error not a valid date: " << std::endl;
			return (false);
		}
		break;
	case 2:
		if (leaps)
		{
			if (d > 28)
			{
				std::cerr << "Error: not a valid date" << std::endl;
				return (false);
			}
		}
		else
		{
			if (d > 29)
				std::cerr << "Error: not a valid date" << std::endl;
			return (false);
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
		std::getline(inp_file, out);
		while (std::getline(inp_file, out))
		{
			if (out.find("|") != out.rfind("|"))
			{
				std::cerr << "Error: bad input => " << out << std::endl;
				continue;
			}
			std::list<std::string> sp = ft_split(out, '|');
			this->sp = sp;

			sp.front() = trim(sp.front());
			sp.back() = trim(sp.back());

			if (sp.size() != 2)
			{
				std::cerr << "Error: bad input => " << sp.front() << std::endl;
				continue;
			}
			this->value = (double)std::atof(sp.back().c_str());
			if (value < 0 || value > 1000)
			{
				std::cerr << (value > 1000 ? "Error: too large a number " : "Error: not a positive number") << std::endl;
				continue;
			}
			if(!checkDashInDate(sp.front()) || !checkIsValidValue(sp.back()))
				continue;
			std::list<std::string> a = ft_split(sp.front(), '-');
			
			if (a.size() != 3)
			{
				std::cerr << "Error: not a valid date => " << a.front() << std::endl;
				continue;
			}
	
			if(bitcoinExchange(a))
				continue;
		}
	}
	else
		std::cerr << "Error : could not open file" << std::endl;
}

bool BitcoinExchange::bitcoinExchange(std::list<std::string> a)
{
	std::list<std::string>::iterator it = a.begin();
	int y = (int)std::atof((*it).c_str());
	int m = (int)std::atof((*++it).c_str());
	int d = (int)std::atof((*++it).c_str());

	
	if (!ParseDate(y, m, d))
		return (true);
		
	if (_data.find(sp.front()) != _data.end())
		std::cout << sp.front() << " => " << sp.back() << " = " << _data[sp.back()] * value << std::endl;
		
	else
	{
		std::map<std::string, double>::iterator it = this->_data.lower_bound(sp.front());
		if (it == _data.begin())
			return true;
		it--;
		std::cout << sp.front() << " => " << sp.back() << " = " << it->second * this->value << std::endl;
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
