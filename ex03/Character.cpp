/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:18:22 by lomont            #+#    #+#             */
/*   Updated: 2025/11/19 04:16:31 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <cstdio>

Character::Character( void ) {
	std::cout << "Default Character constructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->materiaLeftBehindSize = 0;
	this->materiaLeftBehindMemorySize = 0;
	this->materiaLeftBehind = NULL;
	return ;
}

Character::Character( std::string const& setName ) : name (setName) {
	std::cout << "Named Character constructor called" << std::endl;
	for (size_t i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	this->materiaLeftBehindSize = 0;
	this->materiaLeftBehindMemorySize = 0;
	this->materiaLeftBehind = NULL;
	return ;
}

Character::Character( Character const& src) : name ( src.name ) {
	std::cout << "Copy Character constructor called!" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		if (src.inventory[i])
			this->inventory[i] = src.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
	materiaLeftBehindSize = src.materiaLeftBehindSize;
	materiaLeftBehindMemorySize = src.materiaLeftBehindMemorySize;
	if (materiaLeftBehindMemorySize > 0)
		materiaLeftBehind = new AMateria* [materiaLeftBehindMemorySize];
	else
		materiaLeftBehind = NULL;
	for (size_t i = 0; i < materiaLeftBehindSize; i++)
		materiaLeftBehind[i] = src.materiaLeftBehind[i]->clone();
	return ;
}

Character& Character::operator=( Character const& other ) {
	std::cout << "Character assignment operator called" << std::endl;

	if (&other != this) {

		this->name = other.name;

		for (size_t i = 0; i < 4; i++) {
			if (this->inventory[i])
				delete this->inventory[i];
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}

		for (size_t i = 0; i < this->materiaLeftBehindSize; i++)
			delete this->materiaLeftBehind[i];
		delete [] materiaLeftBehind;

		materiaLeftBehindSize = other.materiaLeftBehindSize;
		materiaLeftBehindMemorySize = other.materiaLeftBehindMemorySize;

		if (materiaLeftBehindMemorySize > 0)
			materiaLeftBehind = new AMateria* [materiaLeftBehindMemorySize];
		else
			materiaLeftBehind = NULL;

		for (size_t i = 0; i < materiaLeftBehindSize; i++)
			materiaLeftBehind[i] = other.materiaLeftBehind[i]->clone();
	}
	return (*this);
}

Character::~Character( void ) {
	std::cout << "Character destructor called" << std::endl;
	for (size_t i = 0; i < 4; i++) {
		if (this->inventory[i])
			delete this->inventory[i];
	}
	for (size_t i = 0; i < this->materiaLeftBehindSize; i++)
		delete this->materiaLeftBehind[i];
	delete[] materiaLeftBehind;
	return ;
}

std::string const& Character::getName( void ) const {
	return (this->name);
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << "you can't equip an inexistant materia, please focus" << std::endl;
		return ;
	}
	for (size_t i = 0; i < 4; i++) {
		if (!this->inventory[i]) {
			inventory[i] = m;
			std::cout << "Materia perfectly equiped" << std::endl;
			return ;
		}
	}
	std::cout << "Character inventory is full! Can't equip this materia" << std::endl;
	delete m;
	return ;
}

void Character::unequip(int idx) {
	if (idx < 1 || idx > 4) {
		std::cout << "Materia index out of range, please choose an index between 1 and 4" << std::endl;
		return ;
	}

	if (!this->inventory[idx - 1]) {
		std::cout << "You can't unequip an inexistant materia" << std::endl;
		return ;
	}

	// 1. Check if resizing is needed
	if (materiaLeftBehindSize >= materiaLeftBehindMemorySize)
	{
		AMateria** newMemoryArray = new AMateria*[materiaLeftBehindMemorySize + 2];
		for (size_t i = 0; i < materiaLeftBehindSize; i++) {
			newMemoryArray[i] = materiaLeftBehind[i];
		}
		materiaLeftBehindMemorySize += 2;
		delete[] materiaLeftBehind;
		materiaLeftBehind = newMemoryArray;
	}

	// 2. Add the materia to the floor
	materiaLeftBehind[materiaLeftBehindSize] = this->inventory[idx - 1]; // The pointer is moved
	materiaLeftBehindSize++;

	// 3. Empty the inventory slot
	this->inventory[idx - 1] = NULL;
	std::cout << "You have successfully unequiped this materia" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (!this->inventory[idx - 1]) {
		std::cout << "This inventory slot is empty! You can't use this slot" << std::endl;
		return ;
	}
	std::cout << this->name << " is using " << this->inventory[idx - 1]->getType() << " spell on " << target.getName() << std::endl;
	this->inventory[idx - 1]->use(target);
	return ;
}
