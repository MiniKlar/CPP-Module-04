/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:29:35 by lomont            #+#    #+#             */
/*   Updated: 2025/11/19 00:12:56 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) : AMateria( "cure" )
{
	std::cout << "Default Cure constructor called" << std::endl;
	return ;
}

Cure::Cure( std::string const& setType) : AMateria( setType )
{
	std::cout << "Named Cure constructor called" << std::endl;
	return ;
}

Cure::Cure( Cure const& src) : AMateria( src ) {
	std::cout << "Cure copy constructor called" << std::endl;
	return ;
}

Cure& Cure::operator=( Cure const& other) {
	std::cout << "Cure assignment operator called" << std::endl;
	if (&other != this) {
		AMateria::operator=(other);
	}
	return (*this);
}

Cure::~Cure( void )
{
	std::cout << "Cure destructor called" << std::endl;
	return ;
}

AMateria* Cure::clone() const {
	AMateria* result = new Cure("cure");
	return (result);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return;
}
