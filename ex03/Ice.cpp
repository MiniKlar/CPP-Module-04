/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:29:48 by lomont            #+#    #+#             */
/*   Updated: 2025/11/19 00:12:45 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria( "ice" )
{
	std::cout << "Default Ice constructor called" << std::endl;
	return ;
}

Ice::Ice( std::string const& setType) : AMateria( setType )
{
	std::cout << "Named Ice constructor called" << std::endl;
	return ;
}

Ice::Ice( Ice const& src) : AMateria( src ) {
	std::cout << "Ice copy constructor called" << std::endl;
	return ;
}

Ice& Ice::operator=( Ice const& other) {
	std::cout << "Ice assignment operator called" << std::endl;
	if (&other != this) {
		AMateria::operator=(other);
	}
	return (*this);
}

Ice::~Ice( void )
{
	std::cout << "Ice destructor called" << std::endl;
	return ;
}

AMateria* Ice::clone( void ) const {
	AMateria* result = new Ice("ice");
	return (result) ;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}
