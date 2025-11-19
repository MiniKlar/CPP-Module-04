/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:49:07 by lomont            #+#    #+#             */
/*   Updated: 2025/11/19 01:01:45 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef		AMATERIA_HPP
#define		AMATERIA_HPP

#include	<iostream>
#include	<string>

class ICharacter;

class AMateria
{
	protected:
		std::string	type;
	public:
		AMateria( void );
		AMateria( std::string const& type );
		AMateria( AMateria const& src );
		AMateria& operator=( AMateria const& other );
		virtual ~AMateria( void );
		std::string const& getType( void ) const;
		virtual AMateria* clone( void ) const = 0;
		virtual	void use( ICharacter& target );
};

#endif
