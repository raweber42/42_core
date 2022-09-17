/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:20:37 by raweber           #+#    #+#             */
/*   Updated: 2022/09/17 18:15:26 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack(void) {};
		MutantStack(MutantStack const &src) {*this = src;};
		~MutantStack(void) {};

		MutantStack & operator=(MutantStack const &rhs) {this->c = rhs.c;};
		
		typedef typename std::stack<T>::container_type::iterator Iterator;

		Iterator begin() { return this->c.begin(); };
   		Iterator end()   { return this->c.end(); };

	private:

};

#endif
