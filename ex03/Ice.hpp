/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:29:46 by lomont            #+#    #+#             */
/*   Updated: 2025/11/18 23:58:20 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Ice : public AMateria
{
	public:
		Ice( void );
		Ice( std::string const& setType );
		Ice( Ice const& src);
		Ice& operator=( Ice const& other);
		~Ice( void );
		AMateria* clone ( void ) const;
		void use( ICharacter& target );
};

#endif
