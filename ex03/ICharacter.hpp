/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:41:35 by lomont            #+#    #+#             */
/*   Updated: 2025/11/19 00:22:45 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include <string>

class AMateria;

class ICharacter
{
	protected:
		AMateria* 	inventory[4];
		AMateria** 	materiaLeftBehind;
		size_t		materiaLeftBehindMemorySize;
		size_t		materiaLeftBehindSize;
	public:
		virtual ~ICharacter();
		virtual std::string const& getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use( int idx, ICharacter& target) = 0;
};

#endif
