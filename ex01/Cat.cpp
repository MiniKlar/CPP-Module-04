/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:37:04 by lomont            #+#    #+#             */
/*   Updated: 2025/10/27 10:48:32 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat"), Thinker(new Brain()) {
	std::cout << "Default Cat constructor called!" << std::endl;
	return ;
}

Cat::Cat( const Cat& src) : Animal(src), Thinker(src.Thinker ? new Brain(*src.Thinker) : NULL) {
	std::cout << "Copy Cat constructor called!" << std::endl;
	return ;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Brain* tmp = other.Thinker ? new Brain(*other.Thinker) : NULL;
		Animal::operator=(other);
		delete this->Thinker;
		this->Thinker = tmp;
	}
	return (*this);
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor called!" << std::endl;
	delete this->Thinker;
	return ;
}

void Cat::makeSound( void ) const {
	std::cout << "MEOW MEOW" << std::endl;
	return ;
}
