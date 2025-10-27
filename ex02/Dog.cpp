/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:37:05 by lomont            #+#    #+#             */
/*   Updated: 2025/10/27 22:35:52 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : AAnimal("Dog"), Thinker(new Brain()) {
	std::cout << "Default Dog constructor called!" << std::endl;
	return ;
}

Dog::Dog( const Dog& src ) : AAnimal(src), Thinker(src.Thinker ? new Brain (*src.Thinker) : NULL) {
	std::cout << "Copy Dog constructor called!" << std::endl;
	return ;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		Brain* tmp = other.Thinker ? new Brain(*other.Thinker) : NULL;
		AAnimal::operator=(other);
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
