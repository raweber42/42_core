/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:45:58 by raweber           #+#    #+#             */
/*   Updated: 2022/09/04 17:42:47 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <string>
#include <iostream>
#include <iomanip>

class Zombie {

	public:
		Zombie(void);
		~Zombie(void);
		void	announce(void);
		void	give_name(std::string name);

	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif