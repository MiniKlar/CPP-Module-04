/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:37:07 by lomont            #+#    #+#             */
/*   Updated: 2025/10/27 10:49:51 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal( void );
		Animal(std::string const& t);
		Animal( const Animal& src);
		Animal& operator=( const Animal& other);
		virtual ~Animal( void );
		virtual void makeSound( void ) const ;

		//Getter
		const std::string& getType( void ) const;
};

#endif
