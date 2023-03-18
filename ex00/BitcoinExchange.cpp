/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:28 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/18 23:47:38 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include<algorithm>

BitcoinExchange::BitcoinExchange()
{
	// std::cout << "BitcoinExchange Default constructor called" << std::endl;
	this->data = "";
	this->value = 0;
}

BitcoinExchange::BitcoinExchange(float value, std::string data)
{
	// std::cout << "BitcoinExchange constructor " << std::endl;
	this->value = value;
	this->data = data;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	// std::cout << "BitcoinExchange Copy constructor called" << std::endl;
	*this = obj;
}

BitcoinExchange&BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	// std::cout << "BitcoinExchange Copy assignment operator called" << std::endl;
	this->data = obj.data;
	this->value = obj.value;
	return(*this);
}
BitcoinExchange::~BitcoinExchange(){
	// std::cout << "BitcoinExchange Destructor called" << std::endl;
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
				std::cerr << "Error: bad input "<< sp.front() << std::endl;
				continue;
			}
			sp.front() = trim(sp.front());
			sp.back() = trim(sp.back());
			double amount = static_cast<double>(atof(sp.back().c_str()));
			// boost::trim_right(amount);
			if (amount > SIZE_MAX || amount <  MIN)
			{
				std::cerr << "Error: large "<< sp.front() << std::endl;
				continue;
			}
			if (amount < 0 || amount > 1000)
			{
				std::cerr << (amount > 1000 ? " Error: number is large " : "Error: not a positive number.") << std::endl;
				continue;
			}
			for (size_t i = 0; i < sp.back().size(); i++)
			{
				if (sp.back()[i] == '.')
					i++;
				if (!isdigit(sp.back()[i]))
				{
					std::cout << "errrrrrr: " << sp.back()[i] << std::endl;
					return ;
				}
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
		afterTrim = afterTrim.substr(0,i + 1);
	return(afterTrim);
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