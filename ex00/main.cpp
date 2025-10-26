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
    std::cout << "--- Good animals tests ---" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // cat sound
    j->makeSound(); // dog sound
    meta->makeSound(); // animal sound

    delete meta;
    delete j;
    delete i;

    std::cout << "\n--- Wrong animals tests ---" << std::endl;
    const WrongAnimal* wmeta = new WrongAnimal();
    const WrongAnimal* w = new WrongCat();

    std::cout << w->getType() << " " << std::endl;
    w->makeSound(); // will call WrongAnimal::makeSound because not virtual if implemented that way
    wmeta->makeSound();

    delete wmeta;
    delete w;

    return 0;
}
