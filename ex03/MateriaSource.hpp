/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 01:06:19 by lomont            #+#    #+#             */
/*   Updated: 2025/11/19 01:31:45 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_SOURCE_HPP
#define	MATERIA_SOURCE_HPP

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource {
	private:
		AMateria* inventory[4];
	public:
		MateriaSource( void );
		MateriaSource(MateriaSource const &src);
		MateriaSource& operator=(MateriaSource const &other);
		~MateriaSource( void );
		void learnMateria( AMateria* );
		AMateria* createMateria( std::string const& type );
};

#endif
