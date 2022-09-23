/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raweber <raweber@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:12:07 by raweber           #+#    #+#             */
/*   Updated: 2022/09/23 10:01:59 by raweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>

int handlePseudo(std::string input)
{
	int	i;
	std::string pseudoArr[8] = {"inff", "+inff", "-inff", "nanf", "inf", "+inf", "-inf", "nan"};
	
	for (i = 0; i < 8; i++)
		if (!input.compare(pseudoArr[i]))
			break;
	if (i < 8)
	{
		//----------------PRINT CHAR------------------------
		std::cout << "char: Non displayable" << std::endl;
		//------------------------PRINT INT//----------------
		std::cout << "int: Non displayable" << std::endl;
		//------------------------PRINT FLOAT------------------------
		std::string toPrint;
		if (i < 4)
			toPrint = pseudoArr[i];
		else if (i == 7)
			toPrint = "nanf";
		else
			toPrint = "Undefined behavior";
		std::cout << "float: " << toPrint << std::endl;
		//------------------------PRINT DOUBLE------------------------
		if (i > 4)
			toPrint = pseudoArr[i];
		else if (i == 3)
			toPrint = "nan";
		else
			toPrint = "Undefined behavior";
		std::cout << "double: " << toPrint << std::endl;
		return (1);
	}
	return (0);
}

void handleChar(char c)
{
	//----------------PRINT CHAR------------------------
	if (isprint(c))
		std::cout << "char: \'" << c << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	//------------------------PRINT INT//----------------
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	//------------------------PRINT FLOAT------------------------
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	//------------------------PRINT DOUBLE------------------------
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

int main(int argc, char **argv)
{	
	if (argc != 2)
	{
		std::cout << "Error: Wrong number of arguments!" << std::endl;
		return (1);
	}
	
	std::string char_string(argv[1]);
	double		double_value;
	float		float_value;
	char **		endptr;
	
	// char, int, float or double
	if (handlePseudo(char_string))
		return (0);
	if (isdigit(char_string[0]) || char_string.size() > 1)
	{
		endptr = new char*;
		double_value = std::strtod(argv[1], endptr);
		float_value = std::strtof(argv[1], endptr);
		if (**endptr && (strlen(*endptr) != 1 || **endptr != 'f'))
		{
			std::cout << "Error: Invalid input. Only one of: char, int, float or double!" << std::endl;
			return (1);
		}
	}
	else
	{
		handleChar(argv[1][0]);
		return (0);
	}
	//----------------PRINT CHAR------------------------
	if (isprint(floorf(float_value)))
		std::cout << "char: \'" << static_cast<char>(double_value) << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	//------------------------PRINT INT//----------------
	if (double_value > INT_MAX || double_value < INT_MIN)
		std::cout << "int: Non displayable (overflow)" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(double_value) << std::endl;
	//------------------------PRINT FLOAT------------------------
	if (double_value > std::numeric_limits<float>::max() || double_value < -std::numeric_limits<float>::max())
		std::cout << "float: Non displayable (overflow)" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(double_value) << (floorf(double_value)==double_value?".0f":"f")<< std::endl;
	//------------------------PRINT DOUBLE------------------------
	if (double_value == INFINITY || double_value == -INFINITY)
		std::cout << "double: " << double_value << std::endl;
	else
		std::cout << "double: " << double_value << (floor(double_value)==double_value?".0":"") << std::endl;
}

// NOW -> INF etc