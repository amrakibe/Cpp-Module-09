/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:28 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/19 22:23:53 by amrakibe         ###   ########.fr       */
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
			_data[buff1] = std::stod(buff2.c_str());
			//  !! insert  key (data) and value to map
			// _data.insert(make_pair(buff1, std::stod(buff2.c_str())));
		}
	}
	// std::map<std::string, double>::iterator it = _data.begin();
	// while (it != _data.end())
	// {
	// 	std::cout << "key: "  << it->first << " value: " << it->second << std::endl;
	// 	it++;
	// }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj) { *this = obj; }

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

void ParseDate(int y, int m, int d)
{
	bool leaps = false;

	if (y % 4 != 0)
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
				std::cerr << "Error: \n";
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (d > 30)
				std::cerr << "Error: \n";
			break;
		case 2:
			if (leaps)
			{
				if (d > 28)
					std::cerr << "Error: \n";
			}
			else
			{
				if (d > 29)
					std::cerr << "Error: \n";
			}
	}
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
				std::cerr << "Error: bad input => " << sp.front() << std::endl;
				continue;
			}
			sp.front() = trim(sp.front());
			sp.back() = trim(sp.back());
			double value = static_cast<double>(atof(sp.back().c_str()));
			if (value < 0 || value > 1000)
			{
				std::cerr << (value > 1000 ? "Error: number is large " : "Error: not a positive number.") << std::endl;
				continue;
			}
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
			std::list<std::string> a = ex.ft_split(sp.front(), '-');
			if (a.size() != 3)
				std::cerr << "error : " << std::endl;
			std::list<std::string>::iterator it = a.begin();
			int y = (int)std::atof((*it).c_str());
			int m = (int)std::atof((*++it).c_str());
			int d = (int)std::atof((*++it).c_str());
			ParseDate(y, m, d);
			if (_data.find(sp.front()) != _data.end())
			{
				std::cout << sp.front() << " => " << _data[sp.front()] * value << std::endl;
			}
			else
			{
				std::map<std::string, double>::iterator it = _data.lower_bound(sp.front());
				if (it == _data.begin())
				{
					std::cerr << "Error : " << std::endl;
					continue;
				}
				it--;
				std::cout  << sp.front() << " => " << it->second * value << std::endl;
			}
		}
	}
}

// void BitcoinExchange::func()
// {
// 	if (_data.find(sp.front()) != _data.end())
// 	{
// 		std::cout << "data : " << _data[sp.front()] * value << std::endl;
// 	}
// 	else
// 	{
// 		std::map<std::string, double>::iterator it = _data.lower_bound(sp.front());
// 		if (it == _data.begin())
// 		{
// 			std::cerr << "Error : " << std::endl;
// 			return;
// 		}
// 		it--;
// 		std::cout << "data : " << it->second * value << std::endl;
// 	}
// }

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
