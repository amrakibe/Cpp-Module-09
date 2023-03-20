/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:00:34 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/20 21:49:25 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        std::cerr << "Error : invalid number of arguments." << std::endl;
        return (1);
    }
    std::string line, str;
    for (int i = 1; i < argc; i++)
    {
        std::stringstream a(argv[i]);
        while(std::getline(a, line, ' '))
        {
            ParseRpnPolishedNotation(line);
        }
    }
    return (0);
}