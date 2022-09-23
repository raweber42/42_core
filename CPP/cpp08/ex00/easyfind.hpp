/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 08:29:16 by raweber           #+#    #+#             */
/*   Updated: 2022/09/17 12:19:26 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

class NotFoundException : public std::exception {

	const char *what() const throw() {return ("Exception: Element not found in container!");}
};

template<typename T>
typename T::iterator easyfind(T &container, int second) {
	
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), second);
	if (it == container.end())
		throw NotFoundException();
	else
		return (it);
}

#endif