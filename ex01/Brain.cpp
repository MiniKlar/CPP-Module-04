/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:43:35 by lomont            #+#    #+#             */
/*   Updated: 2025/11/19 03:27:04 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Brain constructor called!" << std::endl;
	return ;
}

Brain::Brain(const Brain& src) {
	std::cout << "Brain Copy constructor called!" << std::endl;
	for (int i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i];
	return ;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain assignment operator called" << std::endl;
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
