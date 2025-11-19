/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:49:00 by lomont            #+#    #+#             */
/*   Updated: 2025/11/19 00:23:02 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : type("Default AMateria") {
	std::cout << "Default AMateria constructor called" << std::endl;
	return ;
}

AMateria::AMateria(std::string const& typeString) : type(typeString) {
	std::cout << "Named AMateria constructor called" << std::endl;
	return ;
}

AMateria::AMateria(AMateria const& src) : type(src.type) {
	std::cout << "AMateria Copy constructor called" << std::endl;
	return ;
}

AMateria& AMateria::operator=(AMateria const& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

AMateria::~AMateria( void )
{
	std::cout << "AMateria destructor called" << std::endl;
	return ;
}

std::string const& AMateria::getType( void ) const {
	return (this->type);
}

void AMateria::use(ICharacter& target) {
	(void) target;
	return ;
}
