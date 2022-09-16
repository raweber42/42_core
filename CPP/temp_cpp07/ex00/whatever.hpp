/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:50:21 by raweber           #+#    #+#             */
/*   Updated: 2022/09/16 08:42:00 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void swap(T &x, T &y) {

	T temp;

	temp = x;
	x = y;
	y = temp;
}

template<typename T>
T const & min(T const &x, T const &y) {

	return ((x < y)?x:y);
}

template<typename T>
T const & max(T const &x, T const &y) {

	return ((x > y)?x:y);
}

#endif