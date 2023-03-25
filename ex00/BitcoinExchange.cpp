/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:28 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/25 22:29:11 by amrakibe         ###   ########.fr       */
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
			// !! stod is a forbidden function : use atof
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

BitcoinExchange::~BitcoinExchange(){
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
	BitcoinExchange ex;

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
			std::list<std::string> sp = ex.ft_split(out, '|');

			sp.front() = trim(sp.front());
			sp.back() = trim(sp.back());
			std::string str = sp.back();
			if (sp.size() != 2)
			{
				std::cerr << "Error: bad input => " << sp.front() << std::endl;
				continue;
			}
			double value = (double)std::atof(sp.back().c_str());
			if (value < 0 || value > 1000)
			{
				std::cerr << (value > 1000 ? "Error: too large a number " : "Error: not a positive number") << std::endl;
				continue;
			}
			if (str.find(".") != str.rfind("."))
			{
				std::cerr << "Error: not a valid number" << std::endl;
				continue;
			}
			bool isNumber = true;
			for (size_t i = 0; i < sp.back().size(); i++)
			{
				if(sp.back()[i] == '.')
					continue;
				if (!isdigit(sp.back()[i]))
					isNumber = false;
			}
			if (sp.front().size() > 10 || sp.front().size() < 10)
			{
				std::cerr << "Error not a valid date => " << sp.front() << std::endl;
				continue;
			}
			if(sp.front()[4] != '-' || sp.front()[7] != '-')
			{
				std::cerr << "Error: not a valid date => " << sp.front() << std::endl;
				continue;
			}
			for (size_t i = 0; i < sp.front().size(); i++)
			{
				if(i == 4 || i == 7)
					continue;
				if(!std::isdigit(sp.front()[i]))
				{
					isNumber = false;
					continue;
				}
			}
			if (!isNumber)
			{
				std::cerr << "Error: not a valid Number" << std::endl;
				continue;
			}
			std::list<std::string> a = ex.ft_split(sp.front(), '-');
			if (a.size() != 3)
			{
				std::cerr << "Error: not a valid date => " << a.front() <<std::endl;
				continue;
			}
			// !!
			std::list<std::string>::iterator it = a.begin();
			int y = (int)std::atof((*it).c_str());
			int m = (int)std::atof((*++it).c_str());
			int d = (int)std::atof((*++it).c_str());
			if (!ParseDate(y, m, d))
			{
				continue;
			}
			if (_data.find(sp.front()) != _data.end())
			{
				std::cout << sp.front() << " => " << sp.back() << " = " << _data[sp.front()] * value << std::endl;
			}
			else
			{
				std::map<std::string, double>::iterator it = _data.lower_bound(sp.front());
				if (it == _data.begin())
				{
					continue;
				}
				it--;
				std::cout << sp.front() << " => " << sp.back() << " = " << it->second * value << std::endl;
			}
		}
	}
	else
		std::cerr << "Error : could not open file" << std::endl;
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
