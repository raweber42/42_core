/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 07:08:07 by raweber           #+#    #+#             */
/*   Updated: 2022/09/05 14:17:37 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>
#include <string>

class Weapon {
	
	public:
		Weapon(std::string type);
		~Weapon(void);
		std::string getType(void) const;
		void		setType(std::string new_type);

	private:		
		std::string _type;

};

#endif