/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:01:13 by wscherre          #+#    #+#             */
/*   Updated: 2025/12/20 16:25:11 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <cctype>
# include <cstdlib>
# include <fstream>
# include <iostream>
# include <map>
# include <sstream>
# include <string>

class BitcoinExchange
{
  private:
	std::map<std::string, float> _database;

	void _loadDatabase(const std::string &dbPath);
	bool _isValidDate(const std::string &date) const;
	bool _isValidValue(float value) const;
	float _findExchangeRate(const std::string &date) const;

	BitcoinExchange();

  public:
	BitcoinExchange(const std::string &dbPath);
	BitcoinExchange(const BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();

	void processInputFile(const std::string &inputPath) const;

	class CouldNotOpenFileException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
	class BadInputException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
	class InvalidDatabaseException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

#endif
