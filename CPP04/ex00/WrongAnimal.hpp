#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;

public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &src);
	virtual ~WrongAnimal(void);
	WrongAnimal &operator=(const WrongAnimal &wa);

	std::string getType(void) const;
	void setType(const std::string &type);
	void makeSound(void) const;
};

#endif