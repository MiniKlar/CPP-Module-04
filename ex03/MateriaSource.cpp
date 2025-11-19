/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:07:29 by lomont            #+#    #+#             */
/*   Updated: 2025/11/19 04:15:27 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource( void ) {
	std::cout << "Default MateriaSource constructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const& src) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		if (src.inventory[i])
			this->inventory[i] = src.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	return ;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& other) {
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if (&other != this) {
		for (size_t i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource( void )
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		if (this->inventory[i])
			delete this->inventory[i];
	}
	return ;
}

void MateriaSource::learnMateria( AMateria* ptr) {
	if (!ptr) {
		std::cout << "Inexistant AMateria, please focus" << std::endl;
		return ;
	}
	for (size_t i = 0; i < 4; i++) {
		if (!this->inventory[i]) {
			this->inventory[i] = ptr;
			return ;
		}
	}
	std::cout << "MateriaSource inventory full, you can't store this materia" << std::endl;
	delete ptr;
	return ;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	if (type == "ice" || type == "cure") {
		for (size_t i = 0; i < 4; i++) {
			if (this->inventory[i]) {
				if (this->inventory[i]->getType() == type)
				return (this->inventory[i]->clone());
			}
		}
	}
	std::cout << "Wrong materia name or materia not learned yet" << std::endl;
	return (0);
}
