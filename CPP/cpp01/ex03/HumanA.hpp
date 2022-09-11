/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 07:06:56 by raweber           #+#    #+#             */
/*   Updated: 2022/09/05 14:49:31 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include "Weapon.hpp"

class HumanA {
	
	public:
		HumanA(std::string name, Weapon &weapon_name);
		~HumanA(void);
		void		attack(void);

	private:
		Weapon		&weapon;
		std::string _name;
};

#endif