/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:04:48 by raweber           #+#    #+#             */
/*   Updated: 2022/09/21 09:36:19 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter {

	public:
		Character(void);
		Character(std::string new_name);
		Character(Character const &src);
		~Character(void);
		Character & operator=(Character const &rhs);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		// my helper:
		void setName(std::string new_name);


	private:
		std::string name;
		AMateria *inventory[4];
		
};

#endif