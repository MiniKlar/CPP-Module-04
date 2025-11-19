/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:18:40 by lomont            #+#    #+#             */
/*   Updated: 2025/11/19 01:30:53 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	name;
	public:
		Character( void );
		Character( std::string const& setName );
		Character( Character const& src);
		Character& operator=( Character const& other);
		~Character( void );
		std::string const& getName( void ) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use( int idx, ICharacter& target);
};

#endif
