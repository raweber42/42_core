/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 09:25:55 by raweber           #+#    #+#             */
/*   Updated: 2022/09/13 13:03:39 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {

	public:
		Bureaucrat(void);
		Bureaucrat(std::string new_name);
		Bureaucrat(std::string new_name, size_t grade);
		~Bureaucrat(void);
		Bureaucrat(Bureaucrat const &src);
		
		Bureaucrat & operator=(Bureaucrat const &rhs);
		
		const std::string 	getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(AForm &form);

		
		//--------Exception classes-------------------//
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Exception: Grade is too high!");
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what () const throw () {
					return ("Exception: Grade is too low!");
				}
		};
		//--------Exception classes end ---------------//

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif