/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:19:36 by raweber           #+#    #+#             */
/*   Updated: 2022/09/10 15:51:35 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria {
	
	public:
		AMateria(void);
		AMateria(AMateria const &src);
		virtual ~AMateria(void);
		AMateria & operator=(AMateria const &rhs);
	
		AMateria(std::string const & type);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		//my stuff
		void setType(std::string);
		
	
	protected:
		std::string type;
};

// MORE STUFF NEEDED HERE!

#endif