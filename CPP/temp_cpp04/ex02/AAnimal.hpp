/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:35:54 by raweber           #+#    #+#             */
/*   Updated: 2022/09/10 10:12:32 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal {
	
	public:
		AAnimal(void);
		AAnimal(AAnimal const &src);
		virtual ~AAnimal(void);
		AAnimal & operator=(AAnimal const &rhs);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0; // new

	protected:
		std::string _type;

	private:

};

#endif