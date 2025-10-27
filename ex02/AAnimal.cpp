/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:37:02 by lomont            #+#    #+#             */
/*   Updated: 2025/10/27 22:57:39 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : type("Alban") {
	std::cout << "Default AAnimal constructor called!" << std::endl;
	return ;
}

AAnimal::AAnimal( const AAnimal& src) : type (src.type) {
	std::cout << "Copy AAnimal constructor called!" << std::endl;
	return ;
}

AAnimal::AAnimal( std::string const &t ) : type(t) {
	std::cout << "AAnimal( std::string ) constructor called!" << std::endl;
	return ;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

AAnimal::~AAnimal( void ) {
	std::cout << "AAnimal Destructor called!" << std::endl;
	return ;
}

const std::string& AAnimal::getType( void ) const {
	return (this->type);
}
