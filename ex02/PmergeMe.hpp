/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:09:03 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/29 21:14:52 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <time.h>


std::vector<int> merge(std::vector<int> left_arr, std::vector<int> right_arr);
std::vector<int> merge_sort(std::vector<int> vector);
std::vector<int> insert_sort(std::vector<int> arr);
std::deque<int> merge(std::deque<int> left_deque, std::deque<int> right_deque);
std::deque<int> merge_sort(std::deque<int> deque);
std::deque<int> insert_sort(std::deque<int> deq);

#endif