/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 08:48:00 by raweber           #+#    #+#             */
/*   Updated: 2022/09/16 14:48:24 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void	iter(T *arr, int arr_len, void (*func)(T &)) {
	
	for (int i = 0; i < arr_len; i++)
		func(arr[i]);
}

void printOut(std::string & str) {

	std::cout << str << std::endl;
}

void makeBoring(std::string & str) {

	str = "boooooring";
}

#endif