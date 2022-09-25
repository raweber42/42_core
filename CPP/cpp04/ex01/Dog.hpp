/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:36:25 by raweber           #+#    #+#             */
/*   Updated: 2022/09/25 11:25:05 by raweber          ###   ########.fr       */
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
		void setIdea(int i, std::string new_idea);


	private:
		Brain *brain;
};


#endif