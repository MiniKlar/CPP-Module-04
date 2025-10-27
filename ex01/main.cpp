/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 00:53:53 by lomont            #+#    #+#             */
/*   Updated: 2025/10/23 02:10:00 by assistant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

int main()
{
    std::cout << "--- Create array of Animals (Dogs and Cats) ---" << std::endl;

    const int ARRAY_SIZE = 6; // even number
    Animal* animals[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (i < ARRAY_SIZE / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n-- Call getType() and makeSound() on each --" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        std::cout << animals[i]->getType() << " -> ";
        animals[i]->makeSound();
    }

    std::cout << "\n--- Deleting array elements via base pointers ---" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        delete animals[i];
    }

    std::cout << "\n--- Deep copy checks ---" << std::endl;
    {
        std::cout << "Dog copy constructor test:" << std::endl;
        Dog* d1 = new Dog();
        Dog* d2 = new Dog(*d1); // should call Brain copy ctor
        delete d1; // d2 should keep its own Brain
        d2->makeSound();
        delete d2;

        std::cout << "\nDog operator= test:" << std::endl;
        Dog da;
        Dog db;
        db = da; // should deep-copy

        std::cout << "Cat copy constructor test:" << std::endl;
        Cat* c1 = new Cat();
        Cat* c2 = new Cat(*c1);
        delete c1;
        c2->makeSound();
        delete c2;

        std::cout << "\nCat operator= test:" << std::endl;
        Cat ca;
        Cat cb;
        cb = ca;
    }

    std::cout << "\n--- Wrong animals tests ---" << std::endl;
    const WrongAnimal* wmeta = new WrongAnimal();
    const WrongAnimal* w = new WrongCat();

    std::cout << w->getType() << " " << std::endl;
    w->makeSound(); // demonstrates non-virtual behavior in WrongAnimal hierarchy
    wmeta->makeSound();

    delete wmeta;
    delete w;

    std::cout << "\nEnd of program." << std::endl;
    return 0;
}
