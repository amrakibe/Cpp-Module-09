/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:10:35 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/26 02:18:40 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange	bitcoin;
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (0);
	}
	else
		bitcoin.ParseBitcoin(av);
	return (0);
}
