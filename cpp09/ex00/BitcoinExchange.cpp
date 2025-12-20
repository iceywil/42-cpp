/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:01:01 by wscherre          #+#    #+#             */
/*   Updated: 2025/12/20 16:25:14 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string &dbPath)
{
	_loadDatabase(dbPath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		this->_database = rhs._database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::_loadDatabase(const std::string &dbPath)
{
		float price;

	std::ifstream dbFile(dbPath.c_str());
	if (!dbFile.is_open())
	{
		throw CouldNotOpenFileException();
	}
	std::string line;
	std::getline(dbFile, line);
	while (std::getline(dbFile, line))
	{
		std::stringstream ss(line);
		std::string date;
		std::string priceStr;
		if (std::getline(ss, date, ',') && std::getline(ss, priceStr))
		{
			std::stringstream priceSS(priceStr);
			if (priceSS >> price)
				this->_database[date] = price;
		}
	}
	if (this->_database.empty())
	{
		throw InvalidDatabaseException();
	}
}

bool BitcoinExchange::_isValidDate(const std::string &date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	int year, month, day;
	char dash1, dash2;
	std::istringstream ss(date);
	ss >> year >> dash1 >> month >> dash2 >> day;

	if (ss.fail() || dash1 != '-' || dash2 != '-')
	{
		return (false);
	}
	if (month < 1 || month > 12 || day < 1 || day > 31)
	{
		return (false);
	}
	return (true);
}

bool BitcoinExchange::_isValidValue(float value) const
{
	return (value >= 0 && value <= 1000);
}

float BitcoinExchange::_findExchangeRate(const std::string &date) const
{
	std::map<std::string,
		float>::const_iterator it = this->_database.lower_bound(date);

	if (it != this->_database.end() && it->first == date)
	{
		return (it->second);
	}

	if (it == this->_database.begin())
	{
		return (-1);
	}

	--it;
	return (it->second);
}

void BitcoinExchange::processInputFile(const std::string &inputPath) const
{
	std::ifstream inputFile(inputPath.c_str());
	if (!inputFile.is_open())
	{
		throw CouldNotOpenFileException();
	}

	std::string line;
	std::getline(inputFile, line);

	do
	{
		if (line.empty() || line == "date | value")
			continue ;

		std::stringstream ss(line);
		std::string date, separator, valueStr;
		float value;

		if (!(ss >> date >> separator >> valueStr) || separator != "|")
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		std::stringstream valueSS(valueStr);
		if (!(valueSS >> value))
		{
			std::cerr << "Error: not a valid number." << std::endl;
			continue ;
		}

		if (!_isValidDate(date))
			std::cerr << "Error: bad input => " << date << std::endl;
		else if (value < 0)
			std::cerr << "Error: not a positive number." << std::endl;
		else if (value > 1000)
			std::cerr << "Error: too large a number." << std::endl;
		else
		{
			float rate = _findExchangeRate(date);
			if (rate < 0)
			{
				std::cerr << "Error: no data for date => " << date << std::endl;
			}
			else
			{
				std::cout << date << " => " << value << " = " << (value
					* rate) << std::endl;
			}
		}

	} while (std::getline(inputFile, line));
}

const char *BitcoinExchange::CouldNotOpenFileException::what() const throw()
{
	return ("Error: could not open file.");
}
const char *BitcoinExchange::BadInputException::what() const throw()
{
	return ("Error: bad input format.");
}
const char *BitcoinExchange::InvalidDatabaseException::what() const throw()
{
	return ("Error: database is empty or invalid.");
}
