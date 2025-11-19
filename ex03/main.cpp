/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:11:48 by lomont            #+#    #+#             */
/*   Updated: 2025/11/19 04:18:53 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main( void ) {
	std::cout << "--- 1. MateriaSource Basic Tests ---" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << "\n-> Learning a 5th materia (should be deleted by learnMateria to avoid leaks)" << std::endl;
	src->learnMateria(new Ice());
	std::cout << std::endl;

	std::cout << "--- 2. Character Basic Tests ---" << std::endl;
	ICharacter* me = new Character("Cloud");
	AMateria* tmp;

	std::cout << "\n-> Creating and equipping materias" << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("fire");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << "\n-> Equipping a 5th materia (should be deleted by equip to avoid leaks)" << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	std::cout << std::endl;

	std::cout << "--- 3. Using Materias ---" << std::endl;
	ICharacter* bob = new Character("Sephiroth");
	std::cout << "Cloud's turn:" << std::endl;
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(4, *bob);
	me->use(5, *bob);
	me->use(2, *bob);
	std::cout << std::endl;

	std::cout << "--- 4. Unequip and Floor Test ---" << std::endl;
	std::cout << "-> Unequipping materia at index 1 (Cure)" << std::endl;
	me->unequip(1);
	std::cout << "-> Using materia at index 1 (should be empty)" << std::endl;
	me->use(1, *bob);
	std::cout << "-> Equipping new materia at index 1" << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->use(1, *bob);
	std::cout << std::endl;

	std::cout << "--- 5. Deep Copy and Assignment Tests ---" << std::endl;
	std::cout << "\n-> Character Copy Constructor Test" << std::endl;
	Character* cloud_clone = new Character(*(static_cast<Character*>(me)));
	std::cout << "Cloned character's turn (using index 1 and 2):" << std::endl;
	cloud_clone->use(1, *bob);
	cloud_clone->use(2, *bob);
	cloud_clone->unequip(1);
	std::cout << "Original character 'me' uses materia at index 1 (should still exist):" << std::endl;
	me->use(1, *bob);

	std::cout << "\n-> Character Assignment Operator Test" << std::endl;
	Character* tifa = new Character("Tifa");
	tmp = src->createMateria("cure");
	tifa->equip(tmp);
	std::cout << "Before assignment, Tifa uses materia at index 1:" << std::endl;
	tifa->use(1, *bob);
	std::cout << "Assigning 'me' to 'Tifa'..." << std::endl;
	*tifa = *(static_cast<Character*>(me));
	std::cout << "After assignment, Tifa uses materia at index 1:" << std::endl;
	tifa->use(1, *bob);
	std::cout << std::endl;

	std::cout << "--- 6. Cleaning up ---" << std::endl;
	delete tifa;
	delete cloud_clone;
	delete bob;
	delete me;
	delete src;

	std::cout << "\n--- End of tests. Check for leaks with valgrind. ---" << std::endl;

	return 0;
}
