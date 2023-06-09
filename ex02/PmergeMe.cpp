/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:09:00 by amrakibe          #+#    #+#             */
/*   Updated: 2023/04/01 00:44:39 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	swap(int &f, int &s)
{
	int tmp = f;
	f = s;
	s = tmp;
}

std::vector<int> merge_sort(std::vector<int> &vector)
{
	int	resize;

	if (vector.size() <= 100)
		return insert_sort(vector);

	resize = vector.size() / 2;
	std::vector<int> left_vector(vector.begin(), vector.begin() + resize);
	std::vector<int> right_vector(vector.begin() + resize, vector.end());

	left_vector = merge_sort(left_vector);
	right_vector = merge_sort(right_vector);

	return (merge(left_vector, right_vector));
}

std::vector<int> merge(std::vector<int> &left_vector, std::vector<int> &right_vector)
{
	std::vector<int> result;
	double i = 0, j = 0;

	for (; i < left_vector.size() && j < right_vector.size();)
	{
		if (left_vector[i] < right_vector[j])
			result.push_back(left_vector[i++]);
		else
			result.push_back(right_vector[j++]);
	}
	for (; i < left_vector.size(); i++)
	{
		result.push_back(left_vector[i]);
	}
	for (; j < right_vector.size(); j++)
	{
		result.push_back(right_vector[j]);
	}
	return (result);
}

std::vector<int> insert_sort(std::vector<int> &vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = i; j > 0 && vec[j] < vec[j - 1]; j--)
		{
			swap(vec[j], vec[j - 1]);
		}
	}
	return (vec);
}

// !! deque part

std::deque<int> merge_sort(std::deque<int> &deque)
{
    if (deque.size() <= 100)
        return (insert_sort(deque));

    int resize = deque.size() / 2;
    std::deque<int> left_deque(deque.begin(), deque.begin() + resize);
    std::deque<int> right_deque(deque.begin() + resize, deque.end());

    left_deque = merge_sort(left_deque);
    right_deque = merge_sort(right_deque);

    return (merge(left_deque, right_deque));
}

std::deque<int> merge(std::deque<int> &left_deque, std::deque<int> &right_deque)
{
    std::deque<int> result;
    double i = 0, j = 0;

	for (; i < left_deque.size() && j < right_deque.size();)
	{
		if (left_deque[i] < right_deque[j])
			result.push_back(left_deque[i++]);
		else
			result.push_back(right_deque[j++]);
    }
	for (; i < left_deque.size(); i++)
	{
		result.push_back(left_deque[i]);
	}
	for (; j < right_deque.size(); j++)
    {
		result.push_back(right_deque[j]);
	}
	return (result);
}


std::deque<int> insert_sort(std::deque<int> &deq)
{
	for (size_t i = 0; i < deq.size(); i++)
	{
		for (size_t j = i; j > 0 && deq[j] < deq[j - 1]; j--)
		{
			swap(deq[j], deq[j - 1]);
		}
	}
	return (deq);
}
