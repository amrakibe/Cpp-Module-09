/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:00:34 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/30 20:50:07 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error : invalid number of arguments." << std::endl;
        exit(1);
    }
    ParseRpnPolishedNotation(argv[1]);
    return (0);
}