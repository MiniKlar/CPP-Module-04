/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 01:37:50 by lomont            #+#    #+#             */
/*   Updated: 2025/10/23 01:38:29 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal( void );
		WrongAnimal(std::string const& t);
		WrongAnimal( const WrongAnimal& src);
		WrongAnimal& operator=( const WrongAnimal& other);
		~WrongAnimal( void );
		void makeSound( void ) const ;

		//Getter
		const std::string& getType( void ) const;
};

#endif
