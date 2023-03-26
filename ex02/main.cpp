/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:38:31 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/26 15:41:39 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av) 
{
    std::vector<int> sequence; 
    if (ac <= 1)
	{
        std::cout << "error" << std::endl;
		return (1);
    }
    int i = 1;
    size_t j;
    while (av[i])
    {
		j = 0;
		for (; av[i][j]; j++)
		{
			if (!std::isdigit(av[i][j]))
				return (std::cout << "error" << std::endl, 1);
        } 
		if (std::atof(av[i]) > INT_MAX || std::atof(av[i]) < INT_MIN)
            return (std::cout << "error" << std::endl, 1);
        if(j == 0)
            return (std::cout << "error: bad input is empty" << std::endl, 1);
            sequence.push_back(std::atof(av[i]));
        i++;
    }
    std::cout << "Before: " ;
    for (size_t i = 1; av[i]; i++)
    {
        std::cout << av[i] << " ";
    }
    // !! this is merge sort
    // std::vector<int> sorted_sequence = merge_sort(sequence);
    // !! this is insertion sort
    std::vector<int> sorted_sequence = insert_sort(sequence);
    
    std::cout << std::endl <<"After: ";
    for (size_t i = 0; i < sorted_sequence.size(); i++)
    {
        std::cout << sorted_sequence[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
