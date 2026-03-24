/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzo <enzo@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:43:55 by enchevri          #+#    #+#             */
/*   Updated: 2026/03/24 02:02:46 by enzo             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "color.h"
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

static bool isChar(const std::string &s)
{
	if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
	{
		std::cout << s << " is a char " << std::endl;
		return true;
	}
	return false;
}

static bool isPseudo(const std::string &s)
{
	if (s == "nan" || s == "nanf" || s == "+inf" || s == "+inff"
		|| s == "-inf" || s == "-inff")
	{
		std::cout << s << " is a pseudo-literal " << std::endl;
		return true;
	}
	return false;
}

static bool isInteger(const std::string &s)
{
	if (s.empty())
		return false;
	size_t start = (s[0] == '-' || s[0] == '+') ? 1 : 0;
	if (start == s.size())
		return false;
	for (size_t i = start; i < s.size(); i++)
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	std::cout << s << " is an integer " << std::endl;
	return true;
}

static bool isFloat(const std::string &s)
{
	char *endptr;
	std::strtof(s.c_str(), &endptr);
	if (*endptr == 'f' && *(endptr + 1) == '\0')
	{
		std::cout << s << " is a float " << std::endl;
		return true;
	}
	return false;
}

static bool isDouble(const std::string &s)
{
	const char *start = s.c_str();
	char *endptr;
	std::strtod(start, &endptr);
	if (endptr != start && *endptr == '\0')
	{
		std::cout << s << " is a double " << std::endl;
		return true;
	}
	return false;
}

static double getPseudoValue(const std::string &s)
{
	if (s == "nan" || s == "nanf")
		return std::numeric_limits<double>::quiet_NaN();
	else if (s == "+inf" || s == "+inff")
		return std::numeric_limits<double>::infinity();
	else
		return -std::numeric_limits<double>::infinity();
}

static void printChar(double val)
{
	if (std::isnan(val) || std::isinf(val) || val < 0 || val > 127)
		std::cout << BRED "char: impossible" << RESET << std::endl;
	else if (!std::isprint(static_cast<unsigned char>(val)))
		std::cout << BYELLOW "char: Non displayable" << RESET << std::endl;
	else
		std::cout << BGREEN "char: '" << static_cast<char>(val) << "'" << RESET << std::endl;
}

static void printInt(double val)
{
	if (std::isnan(val) || std::isinf(val) || val > INT_MAX || val < INT_MIN)
		std::cout << BRED "int: impossible" << RESET << std::endl;
	else
		std::cout << BGREEN "int: " << static_cast<int>(val) << RESET << std::endl;
}

static void printFloat(double val)
{
	if (std::isnan(val))
		std::cout << BGREEN "float: nanf" << RESET << std::endl;
	else if (std::isinf(val))
		std::cout << BGREEN "float: " << (val > 0 ? "+inff" : "-inff") << RESET << std::endl;
	else if (val > FLT_MAX || val < -FLT_MAX)
		std::cout << BRED "float: impossible" << RESET << std::endl;
	else
		std::cout << BGREEN "float: " << static_cast<float>(val) << "f" << RESET << std::endl;
}

static void printDouble(double val)
{
	if (std::isnan(val))
		std::cout << BGREEN "double: nan" << RESET << std::endl;
	else if (std::isinf(val))
		std::cout << BGREEN "double: " << (val > 0 ? "+inf" : "-inf") << RESET << std::endl;
	else
		std::cout << BGREEN "double: " << val << RESET << std::endl;
}

static void printAll(double val)
{
	printChar(val);
	printInt(val);
	printFloat(val);
	printDouble(val);
}

void ScalarConverter::convert(std::string const &s)
{
	std::cout.precision(1);
	std::cout << std::fixed;
	if (isChar(s))
		printAll(static_cast<double>(s[1]));
	else if (isPseudo(s))
		printAll(getPseudoValue(s));
	else if (isInteger(s))
		printAll(std::strtod(s.c_str(), NULL));
	else if (isFloat(s))
		printAll(static_cast<double>(std::strtof(s.c_str(), NULL)));
	else if (isDouble(s))
		printAll(std::strtod(s.c_str(), NULL));
	else
		std::cout << "Error: not a valid literal" << std::endl;
}
