/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:35 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/29 20:48:38 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange	bitcoin;
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (0);
	}
	else
		bitcoin.ParseBitcoin(av);
	return (0);
}
