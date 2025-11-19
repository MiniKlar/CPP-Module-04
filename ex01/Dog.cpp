/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:37:05 by lomont            #+#    #+#             */
/*   Updated: 2025/11/19 03:25:23 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal("Dog"), Thinker(new Brain()) {
	std::cout << "Default Dog constructor called!" << std::endl;
	return ;
}

Dog::Dog( const Dog& src ) : Animal(src), Thinker(src.Thinker ? new Brain (*src.Thinker) : NULL) {
	std::cout << "Copy Dog constructor called!" << std::endl;
	return ;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other) {
		Brain* tmp = other.Thinker ? new Brain(*other.Thinker) : NULL;
		Animal::operator=(other);
		delete this->Thinker;
		this->Thinker = tmp;
	}
	return (*this);
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called!" << std::endl;
	delete this->Thinker;
	return ;
}

void Dog::makeSound( void ) const {
	std::cout << "BARK BARK" << std::endl;
	return ;
}
