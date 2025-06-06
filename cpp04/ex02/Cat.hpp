/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a <a@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 20:53:29 by a                 #+#    #+#             */
/*   Updated: 2025/06/04 22:31:45 by a                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <string>

class Cat : public Animal
{
  private:
	Brain *_brain;

  public:
	Cat();
	Cat(Cat const &src);
	virtual ~Cat();
	Cat &operator=(Cat const &rhs);

	void makeSound() const;
	void setIdea(int index, const std::string &idea);
	std::string getIdea(int index) const;
};

#endif
