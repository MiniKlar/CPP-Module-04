/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:29:33 by lomont            #+#    #+#             */
/*   Updated: 2025/11/19 00:00:47 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef Cure_HPP
#define Cure_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Cure : public AMateria
{
	public:
		Cure( void );
		Cure( std::string const& setType );
		Cure( Cure const& src);
		Cure& operator=( Cure const& other);
		~Cure( void );
		AMateria* clone( void ) const;
		void use( ICharacter& target );
};

#endif
