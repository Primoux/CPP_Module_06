/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:43:55 by enchevri          #+#    #+#             */
/*   Updated: 2026/03/18 18:31:46 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <ScalarConverter.hpp>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

static void	debugPrint(std::string const &s)
{
	std::cout << "DEBUG : " BRED << s << RESET << std::endl;
}

void	isInteger(const std::string &s)
{
	size_t	start;

	start = (s[0] == '-' || s[0] == '+') ? 1 : 0;
	for (size_t i = start; i < s.size(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return;
	}
	long n = std::strtol(s.c_str(), 0, 10);
	std::cout << BBLUE << s << " : is a integer" RESET << std::endl;
	std::cout << BYELLOW << static_cast<unsigned char>(n) << " : in char" << RESET << std::endl;
	std::cout << BCHARTREUSE << static_cast<float>(n) << " : in float" << RESET << std::endl;
	std::cout << BROSE <<static_cast<double>(n) << " : in double" << RESET << std::endl;

	return;
}


void ScalarConverter::convert(std::string const &s)
{
	
	isInteger(s);
	debugPrint(s);
}
