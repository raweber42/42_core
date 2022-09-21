/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:35:54 by raweber           #+#    #+#             */
/*   Updated: 2022/09/09 16:34:42 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
	
	public:
		Animal(void);
		Animal(Animal const &src);
		virtual ~Animal(void);

		Animal & operator=(Animal const &rhs);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;

	protected:
		std::string _type;

	private:

};

#endif