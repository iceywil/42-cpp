/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:02:16 by wscherre          #+#    #+#             */
/*   Updated: 2025/12/20 16:02:18 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <exception>

class RPN {
    private:
        RPN();
        RPN(const RPN& src);
        RPN& operator=(const RPN& rhs);
        ~RPN();

    public:
        static void evaluate(const std::string& expression);
};

#endif
