/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:45:58 by raweber           #+#    #+#             */
/*   Updated: 2022/09/04 15:05:52 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>
#include <iomanip>

class Zombie {

	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
		Zombie*	newZombie( std::string name );
		void	randomChump( std::string name );

	private:
		std::string name;
};

#endif