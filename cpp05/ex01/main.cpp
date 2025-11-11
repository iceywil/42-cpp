/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscherre <wscherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:51:06 by wscherre          #+#    #+#             */
/*   Updated: 2025/11/11 15:45:39 by wscherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
    Bureaucrat will("Will", 130);
    Bureaucrat tom("Tom", 5);
    Form form("Contract", 129, 50);

    std::cout << will;
    std::cout << tom;
    std::cout << form;

    try{
        will.signForm(form);
    }
    catch(Form::GradeTooLowException &e){
        std::cout << will.getName() << " can't sign the form: \"" << form.getName() << "\" " << e.what() << std::endl;
    }
    std::cout << form;

    try{
        tom.signForm(form);
    }
    catch(Form::GradeTooLowException &e){
        std::cout << tom.getName() << " can't sign the form: \"" << form.getName() << "\" " << e.what() << std::endl;
    }
    std::cout << form;
}