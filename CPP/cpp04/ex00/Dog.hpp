/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:36:25 by raweber           #+#    #+#             */
/*   Updated: 2022/09/09 16:05:48 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal {
	
	public:
		Dog(void);
		Dog(Dog const &src);
		~Dog(void);

		Dog & operator=(Dog const &rhs);

		void	setType(void);
		void	makeSound(void) const;

	private:

};


#endif