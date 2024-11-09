/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:25:39 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/09 16:12:06 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
class ICharacter; //Forward declaration to avoid circular dependencies.

class AMateria {
protected:
	std::string materiaType;
public:
	AMateria(void);
	AMateria(const std::string &name);
	AMateria(const AMateria &old);
	AMateria &operator=(const AMateria &rhs);
	virtual ~AMateria(void);

	std::string const &getType() const;
	//Pure virtual function to be implemented by derived class.
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target); //Using forward declaration for this reason.
};

#endif

//class ICharacter is forward declaration and need to use when:
//u only need a ref or pointer to the class(ICharacter& or ICharacter*).
//The implementation of the method that use ICharacter is defined in a seperate .cpp file
//where the full definition of ICharacter can be included.


//BENIFIT OF USING FORWARD DECLARATION:
//Reduce Coupling: Your header file won't depend on the full defintion of another class.
//Improve Compilation Time: Less code is included, so the compiler works faster.
//Avoids Circular Dependecies: Prevent issues where 2 header files included each other.