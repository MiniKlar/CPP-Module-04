/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 01:39:16 by lomont            #+#    #+#             */
/*   Updated: 2025/10/23 01:39:18 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("Alban") {
	std::cout << "Default WrongAnimal constructor called!" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal( const WrongAnimal& src) : type (src.type) {
	std::cout << "Copy WrongAnimal constructor called!" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal( std::string const &t ) : type(t) {
	std::cout << "WrongAnimal( std::string ) constructor called!" << std::endl;
	return ;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal Destructor called!" << std::endl;
	return ;
}

void WrongAnimal::makeSound( void ) const {
	std::cout << "** Weird Distant, unidentifiable rawrs**" << std::endl;
	return ;
}

const std::string& WrongAnimal::getType( void ) const {
	return (this->type);
}
