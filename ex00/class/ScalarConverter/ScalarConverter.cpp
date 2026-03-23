/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:43:55 by enchevri          #+#    #+#             */
/*   Updated: 2026/03/19 16:57:12 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <ScalarConverter.hpp>
#include <cctype>
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>
#include "color.h"



static double getIntValue(const std::string &s)
{
	
	return(std::strtod(s.c_str(), NULL));
}

static void printInt(double val)
{
	if (std::isnan(val) || std::isinf(val) || val > INT_MAX || val < INT_MIN)
		std::cout << BRED "int: impossible" << RESET << std::endl;
	else
		std::cout << BGREEN "int: "<< static_cast<int>(val) << RESET <<std::endl;
}

static void	printAll(double val)
{
	// printChar(val);
	printInt(val);
	// printFloat(val);
	// printDouble(val);
}

static bool	isInteger(const std::string &s)
{
	size_t	start;

	if (s.empty())
		return false;
	start = (s[0] == '-' || s[0] == '+') ? 1 : 0;
	if (start == s.size())
		return false;
	for (size_t i = start; i < s.size(); i++)
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	return true;
}

static bool isChar(const std::string &s)
{
	if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
		return true;
	else 
		return false;	
}

void ScalarConverter::convert(std::string const &s)
{
	std::cout.precision(1);
	std::cout << std::fixed;
	if (isChar(s))
		printAll(static_cast<double>(s[1]));
	// else if (isPseudo(s))
	// 	printAll(getPseudoValue(s));
	else if (isInteger(s))
		printAll(getIntValue(s));
	// else if (isFloat(s))
	// 	printAll(static_cast<double>(std::strtof(s.c_str(), 0)));
	// else if (isDouble(s))
	// 	printAll(std::strtod(s.c_str(), 0));
	// else
	// 	std::cout << "Error: not a valid literal" << std::endl;
}
