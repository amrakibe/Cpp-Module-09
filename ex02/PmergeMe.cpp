/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:09:00 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/24 00:31:45 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> merge_sort(std::vector<int> vector)
{
    if (vector.size() <= 1)
    {
        return vector;
    }
    int resize = vector.size() / 2;
    std::vector<int> left_vector(vector.begin(), vector.begin() + resize);
    std::vector<int> right_vector(vector.begin() + resize, vector.end());

    left_vector = merge_sort(left_vector);
    right_vector = merge_sort(right_vector);

    return merge(left_vector, right_vector);
}

std::vector<int> merge(std::vector<int> left_vector, std::vector<int> right_vector)
{
    std::vector<int> result;

    double left_index = 0;
    double right_index = 0;

    for (; left_index < left_vector.size() && right_index < right_vector.size();)
    {
        if (left_vector[left_index] < right_vector[right_index])
        {
            result.push_back(left_vector[left_index]);
            left_index++;
        }
        else
        {
            result.push_back(right_vector[right_index]);
            right_index++;
        }
    }

    for (;left_index < left_vector.size(); left_index++)
    {
        result.push_back(left_vector[left_index]);
    }

    for (;right_index < right_vector.size() ; right_index++)
    {
        result.push_back(right_vector[right_index]);
    }
    return result;
}

template <typename T>
void swap(T &f, T &s)
{
	T tmp = f;
	f = s;
	s = tmp;
}

void insert_sort(std::vector<int> &vector)
{
    for (size_t i = 0; i < vector.size(); ++i)
    {
        int j = i;
        while (j > 0 && vector[j] < vector[j - 1])
        {
            swap(vector[j], vector[j - 1]);
            j--;
        }
    }
}
