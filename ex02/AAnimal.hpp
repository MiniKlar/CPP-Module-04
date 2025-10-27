/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 23:37:07 by lomont            #+#    #+#             */
/*   Updated: 2025/10/27 22:56:14 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal( void );
		AAnimal(std::string const& t);
		AAnimal( const AAnimal& src);
		AAnimal& operator=( const AAnimal& other);
		virtual ~AAnimal( void ) = 0;
		virtual void makeSound( void ) const = 0;

		//Getter
		const std::string& getType( void ) const;
};

#endif
