/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 08:04:18 by raweber           #+#    #+#             */
/*   Updated: 2022/09/06 10:45:02 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl {
	
	public:
		Harl();
		~Harl();
		void complain(std::string &level);
		
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif