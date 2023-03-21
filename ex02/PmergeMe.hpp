/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amrakibe <amrakibe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:09:03 by amrakibe          #+#    #+#             */
/*   Updated: 2023/03/21 15:20:31 by amrakibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class PmergeMe
{
private:
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(PmergeMe const &src);
    PmergeMe& operator=(PmergeMe const &rhs);
};


