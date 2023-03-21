/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:09:00 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/21 15:21:00 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(/* args */)
{
}

PmergeMe::~PmergeMe()
{
}
PmergeMe::PmergeMe(PmergeMe const &src)
{
    *this = src;
}
PmergeMe& PmergeMe::operator=(PmergeMe const &rhs)
{
    if (this != &rhs)
    {
    }
    return (*this);
}
