/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:20:56 by raweber           #+#    #+#             */
/*   Updated: 2022/09/15 15:38:19 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <cstdlib>
#include <iostream>

class Base {
	
	public:
		virtual ~Base(void);
		
	private:
};

class A : virtual public Base {
	
};

class B : virtual public Base {
	
};

class C : virtual public Base {
	
};

Base *	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif