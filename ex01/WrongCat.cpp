/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 01:42:48 by lomont            #+#    #+#             */
/*   Updated: 2025/10/23 01:45:47 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat") {
	std::cout << "Default WrongCat constructor called!" << std::endl;
	return ;
}

WrongCat::WrongCat( const WrongCat& src) : WrongAnimal(src) {
	std::cout << "Copy WrongCat constructor called!" << std::endl;
	return ;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destructor called!" << std::endl;
	return ;
}

void WrongCat::makeSound( void ) const {
	std::cout << "weird MEOW MEOW" << std::endl;
	return ;
}
