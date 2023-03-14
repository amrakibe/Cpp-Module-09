/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:35 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/14 19:12:11 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange ex;
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (0);
	}
	std::string name = av[1];
	std::ifstream inp_file(name);
	std::string out;
	if (inp_file.is_open())
	{
		while (std::getline(inp_file, out))
		{
			std::vector<std::string> vc = ex.split(out, '|');
			if(vc.size() != 2)
				std::cerr << "Error: bad input => 2001-42-42" << std::endl;
			std::cout << vc.size() << std::endl;
		}
	}
	else
		std::cerr << "Error 1: could not open file." << std::endl;
	return (0);
}
