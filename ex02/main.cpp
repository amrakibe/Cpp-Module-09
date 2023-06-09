/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:38:31 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/31 22:38:33 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    clock_t cl;
    std::vector<int> sequence;
    std::deque<int> deq;

    if (ac <= 1)
	{
        std::cout << "error" << std::endl;
		return (1);
    }
    size_t j;
    for(size_t i = 1; av[i]; i++)
    {
        j = 0;
		for(;av[i][j]; j++)
		{
			if (!std::isdigit(av[i][j]))
				return (std::cout << "error" << std::endl, 1);
        } 
		if (std::atof(av[i]) > INT_MAX || std::atof(av[i]) < INT_MIN)
            return (std::cout << "error" << std::endl, 1);
        if(j == 0)
            return (std::cout << "error: bad input is empty" << std::endl, 1);
        sequence.push_back(std::atof(av[i]));
        deq.push_back(std::atof(av[i]));
    }

    std::cout << "Before: " ;
    for (size_t i = 1; av[i]; i++)
    {
        std::cout << av[i] << " ";
    }
    
    cl = clock();
    std::vector<int> sorted_sequence = merge_sort(sequence);
    cl = clock() - cl;
    double vec_time = ((double)cl) / CLOCKS_PER_SEC * 1000;

    cl = clock();
    merge_sort(deq);
    cl = clock() - cl;
    double deq_time = ((double)cl) / CLOCKS_PER_SEC * 1000;

    std::cout << std::endl <<"After: ";

    for (size_t i = 0; i < sorted_sequence.size(); i++)
    {
        std::cout << sorted_sequence[i] << " ";
    }

    std::cout << std::endl << "Time to process a range of "<< sequence.size() <<" elements with std::[vector] " << vec_time << " us"  << std::endl;
    std::cout <<  "Time to process a range of "<< deq.size() <<" elements with std::[deque] " << deq_time << " us" << std::endl;
    return 0;
}
