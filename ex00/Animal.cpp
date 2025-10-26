/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:37:02 by lomont            #+#    #+#             */
/*   Updated: 2025/10/23 01:13:50 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : type("Alban") {
	std::cout << "Default Animal constructor called!" << std::endl;
	return ;
}

Animal::Animal( const Animal& src) : type (src.type) {
	std::cout << "Copy Animal constructor called!" << std::endl;
	return ;
}

Animal::Animal( std::string const &t ) : type(t) {
	std::cout << "Animal( std::string ) constructor called!" << std::endl;
	return ;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

Animal::~Animal( void ) {
	std::cout << "Animal Destructor called!" << std::endl;
	return ;
}

void Animal::makeSound( void ) const {
	std::cout << "**Distant, unidentifiable rawrs**" << std::endl;
	return ;
}

const std::string& Animal::getType( void ) const {
	return (this->type);
}
