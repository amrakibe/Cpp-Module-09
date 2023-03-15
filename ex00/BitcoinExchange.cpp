/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:28 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/15 13:46:51 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange Default constructor called" << std::endl;
	this->data = "";
	this->value = 0;
}

BitcoinExchange::BitcoinExchange(float value, std::string data)
{
	std::cout << "BitcoinExchange constructor " << std::endl;
	this->value = value;
	this->data = data;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &obj)
{
	std::cout << "BitcoinExchange Copy constructor called" << std::endl;
	*this = obj;
}

BitcoinExchange&BitcoinExchange::operator=(const BitcoinExchange &obj)
{
	std::cout << "BitcoinExchange Copy assignment operator called" << std::endl;
	this->data = obj.data;
	this->value = obj.value;
	return(*this);
}
BitcoinExchange::~BitcoinExchange(){
	std::cout << "BitcoinExchange Destructor called" << std::endl;
}

void BitcoinExchange::test(char **av)
{
    BitcoinExchange *ex = nullptr;
    std::string name = av[1];
	std::ifstream inp_file(name);
	std::string out;
	if (!inp_file.is_open())
	{
		std::cerr << "Error : could not open file." << std::endl;
	}
	else
		while (std::getline(inp_file, out))
		{
			std::vector<std::string> vc = ex->ft_split(out, '|');
            for (size_t i = 0; i < vc.size(); i++)
            {
				std::string aa = vc[i];;
				std::cout << aa << std::endl;
			}
			if(vc.size() != 2)
				std::cerr << "Error: bad input => 2001-42-42" << std::endl;
			std::cout << vc.size() << std::endl;
		}
}

std::vector<std::string> BitcoinExchange::ft_split(std::string length, char delimiter)
{
    std::vector<std::string> vector;

	std::string sub_string;
    std::stringstream input_file(length);
    while (std::getline(input_file, sub_string, delimiter))
        if (sub_string != "")
            vector.push_back(sub_string);
    return vector;
}