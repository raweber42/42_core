/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:36:20 by raweber           #+#    #+#             */
/*   Updated: 2022/09/09 16:11:14 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal {
	
	public:
		WrongCat(void);
		WrongCat(WrongCat const &src);
		~WrongCat(void);

		WrongCat & operator=(WrongCat const &rhs);

		void	setType(void) ;
		void	makeSound(void) const ;

	private:

};


#endif