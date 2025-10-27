/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:43:33 by lomont            #+#    #+#             */
/*   Updated: 2025/10/27 10:49:01 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	protected:
		std::string ideas[100];
	public:
		Brain( void );
		Brain( const Brain& src);
		Brain& operator=( const Brain& other);
		~Brain( void );
};

#endif
