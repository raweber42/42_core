/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:35:54 by raweber           #+#    #+#             */
/*   Updated: 2022/09/09 16:10:46 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal {
	
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &src);
		~WrongAnimal(void);

		WrongAnimal & operator=(WrongAnimal const &rhs);

		std::string getType(void) const ;
		void		makeSound(void) const ;

	protected:
		std::string _type;
		std::string	_sound;

	private:

};

#endif