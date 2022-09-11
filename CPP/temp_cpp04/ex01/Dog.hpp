/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:36:25 by raweber           #+#    #+#             */
/*   Updated: 2022/09/10 09:55:00 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal {
	
	public:
		Dog(void);
		Dog(Dog const &src);
		~Dog(void);

		Dog & operator=(Dog const &rhs);

		void		setType(void);
		void		makeSound(void) const;
		std::string	getIdea(int i) const;

	private:
		Brain *brain;
};


#endif