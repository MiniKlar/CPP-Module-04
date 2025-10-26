/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:37:04 by lomont            #+#    #+#             */
/*   Updated: 2025/10/23 01:14:14 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
	std::cout << "Default Cat constructor called!" << std::endl;
	return ;
}

Cat::Cat( const Cat& src) : Animal(src) {
	std::cout << "Copy Cat constructor called!" << std::endl;
	return ;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor called!" << std::endl;
	return ;
}

void Cat::makeSound( void ) const {
	std::cout << "MEOW MEOW" << std::endl;
	return ;
}
