/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:36:20 by raweber           #+#    #+#             */
/*   Updated: 2022/09/09 16:05:54 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal {
	
	public:
		Cat(void);
		Cat(Cat const &src);
		~Cat(void);

		Cat & operator=(Cat const &rhs);

		void	setType(void);
		void	makeSound(void) const;

	private:

};


#endif