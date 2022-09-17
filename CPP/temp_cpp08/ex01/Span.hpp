/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 15:22:35 by raweber           #+#    #+#             */
/*   Updated: 2022/09/17 16:58:10 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span {

	public:
		Span(void);
		Span(unsigned int n);
		~Span(void);
		Span(Span const &src);

		Span & operator=(Span const &rhs);
		
		int		getSize(void);
		int		getValue(int index);
		void 	addNumber(int number);
		long 	shortestSpan(void);
		long 	longestSpan(void);
		void	addMultiple(std::vector<int> toInsert);

		// ------ EXCEPTIONS ------
		class MaxSizeReachedException : public std::exception {
			public:
				virtual const char *what() const throw() {return ("Exception: Maximum size of array reached!");};
		};

		class NoSpanPossibleException : public std::exception {
			public:
				virtual const char *what() const throw() {return ("Exception: Array has one or less members, no span possible!");};
		};

	private:
		int					_max_length;
		int					_cur_length;
		std::vector<int>	_arr;
};

#endif