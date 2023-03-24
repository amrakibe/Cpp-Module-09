/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:09:03 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/23 21:50:23 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>


std::vector<int> merge(std::vector<int> left_arr, std::vector<int> right_arr);
std::vector<int> merge_sort(std::vector<int> arr);
template <typename T>
void swap(T &f, T &s);