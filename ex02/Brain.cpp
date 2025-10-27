/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:43:35 by lomont            #+#    #+#             */
/*   Updated: 2025/10/27 10:48:46 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Brain constructor called!" << std::endl;
	return ;
}

Brain::Brain(const Brain& src) {
	for (int i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i];
	return ;
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain( void ) {
	std::cout << "Brain destructor called!" << std::endl;
	return ;
}
