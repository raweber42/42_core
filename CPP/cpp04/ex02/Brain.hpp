/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 07:55:18 by raweber           #+#    #+#             */
/*   Updated: 2022/09/10 09:34:58 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
	public:
		Brain(void);
		Brain(Brain const &src);
		~Brain(void);

		Brain & operator=(Brain const &rhs);

		std::string	getIdea(int i) const;

	private:
		std::string _ideas[100];
	
};

#endif