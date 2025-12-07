/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:32:26 by wscherre          #+#    #+#             */
/*   Updated: 2025/12/01 16:30:27 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	*this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

bool ScalarConverter::isInteger(const std::string &literal)
{
	if (literal.empty())
		return (false);
	std::string::const_iterator it = literal.begin();
	if (*it == '+' || *it == '-')
	{
		++it;
	}
	for (; it != literal.end(); ++it)
	{
		if (!std::isdigit(*it))
		{
			return (false);
		}
	}
	return (true);
}

bool ScalarConverter::isFloat(const std::string &literal)
{
	float	f;

	std::istringstream ss(literal);
	ss >> f;
	return (!ss.fail() && ss.eof());
}

bool ScalarConverter::isDouble(const std::string &literal)
{
	double	d;

	std::istringstream ss(literal);
	ss >> d;
	return (!ss.fail() && ss.eof());
}

void ScalarConverter::convert(std::string input)
{
	char *end;

	long to_Int;
	float to_Float;
	double to_Double;
	char to_Char = '\0';


	if (input == "-inff" || input == "+inff" || input == "nanf")
	{
		std::cout << "char: impossible\nint: impossible\n"
					<< "float: " << input << "\ndouble: " << input.substr(0,
						input.size() - 1) << std::endl;
		return ;
	}
	if (input == "-inf" || input == "+inf" || input == "nan")
	{
		std::cout << "char: impossible\nint: impossible\n"
					<< "float: " << input << "f\ndouble: " << input << std::endl;
		return ;
	}


	std::string type;
	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		type = "char";
		to_Char = input[0];
		to_Int = static_cast<int>(to_Char);
		to_Float = static_cast<float>(to_Char);
		to_Double = static_cast<double>(to_Char);
	}
	else if (isInteger(input))
	{
		type = "int";
		errno = 0;
		to_Int = std::strtol(input.c_str(), &end, 10);
		if (errno == ERANGE || (to_Int < std::numeric_limits<int>::min()
				|| to_Int > std::numeric_limits<int>::max()))
		{
			std::cerr << "POSSIBLE INT OVER OR UNDERFLOW, \
				STOPPING EXECUTION HERE " << std::endl;
			return ;
		}
		to_Char = (to_Int >= 32
				&& to_Int <= 126) ? static_cast<char>(to_Int) : '\0';
		to_Float = static_cast<float>(to_Int);
		to_Double = static_cast<double>(to_Int);
	}
	else if (input[input.length() - 1] == 'f' && isFloat(input.substr(0,
				input.size() - 1)))
	{
		type = "float";
		errno = 0;
		to_Float = std::strtof(input.c_str(), &end);
		if (errno == ERANGE)
		{
			std::cerr << "POSSIBLE FLOAT OVER OR UNDERFLOW, \
STOPPING EXECUTION HERE "
						<< std::endl;
			return ;
		}
		to_Int = static_cast<int>(to_Float);
		to_Double = static_cast<double>(to_Float);
		to_Char = (to_Int >= 32
				&& to_Int <= 126) ? static_cast<char>(to_Int) : '\0';
	}
	else if (isDouble(input))
	{
		type = "double";
		errno = 0;
		to_Double = std::strtod(input.c_str(), &end);
		if (errno == ERANGE)
		{
			std::cerr << "POSSIBLE INT OVER OR UNDERFLOW, \
				STOPPING EXECUTION HERE " <<  std::endl;
				return ;
		}
		to_Int = static_cast<int>(to_Double);
		to_Float = static_cast<float>(to_Double);
		to_Char = (to_Int >= 32
				&& to_Int <= 126) ? static_cast<char>(to_Int) : '\0';
	}
	else
	{
		std::cout << "Invalid input: Not a recognizable scalar type." << std::endl;
		return ;
	}

	if (type == "char")
	{
		std::cout << "char: '" << to_Char << "'\n";
	}
	else if (to_Char == '\0')
	{
		std::cout << "char: Non displayable" << std::endl;
	}
	else
	{
		std::cout << "char: '" << to_Char << "'\n";
	}

	if (to_Float < std::numeric_limits<int>::min()
		|| to_Float > std::numeric_limits<int>::max()
		|| to_Double < std::numeric_limits<int>::min()
		|| to_Double > std::numeric_limits<int>::max())
	{
		std::cerr << "int: over or underflow" << std::endl;
	}
	else
		std::cout << "int: " << to_Int << std::endl;
	std::cout << "float: " << to_Float << (to_Float == static_cast<int>(to_Float) ? ".0f" : "f") << std::endl;
	std::cout << "double: " << to_Double << (to_Double == static_cast<int>(to_Double) ? ".0" : "") << std::endl;
}