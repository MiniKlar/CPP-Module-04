/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:37:05 by lomont            #+#    #+#             */
/*   Updated: 2025/10/23 01:14:01 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog") {
	std::cout << "Default Dog constructor called!" << std::endl;
	return ;
}

Dog::Dog( const Dog& src) : Animal(src) {
	std::cout << "Copy Dog constructor called!" << std::endl;
	return ;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called!" << std::endl;
	return ;
}

void Dog::makeSound( void ) const {
	std::cout << "BARK BARK" << std::endl;
	return ;
}
