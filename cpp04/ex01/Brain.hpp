/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:53:29 by a                 #+#    #+#             */
/*   Updated: 2025/06/05 16:54:38 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
  protected:
	std::string _ideas[100];

  public:
	Brain();
	Brain(Brain const &src);
	virtual ~Brain();
	Brain &operator=(Brain const &rhs);

	void setIdea(int index, const std::string &idea);
	std::string getIdea(int index) const;
};

#endif
