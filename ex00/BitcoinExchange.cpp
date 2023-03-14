/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:28 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/14 20:45:43 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::test(char **av)
{
    BitcoinExchange ex;
    std::string name = av[1];
	std::ifstream inp_file(name);
	std::string out;
	if (!inp_file.is_open())
	{
		std::cerr << "Error 1: could not open file." << std::endl;
	}
	else
		while (std::getline(inp_file, out))
		{
			std::vector<std::string> vc = ex.ft_split(out, '|');
			if(vc.size() != 2)
			{
				std::cerr << "Error: bad input => 2001-42-42" << std::endl;
			}
			std::cout << vc.size() << std::endl;
		}
}

std::vector<std::string> BitcoinExchange::ft_split(std::string Length, char delimiter)
{
    std::vector<std::string> vector;
    std::string sub_string;

    std::stringstream input_file(Length);
    while (std::getline(input_file, sub_string, delimiter))
        if (sub_string != "")
            vector.push_back(sub_string);
    return vector;
}