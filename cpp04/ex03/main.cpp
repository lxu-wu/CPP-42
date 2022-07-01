#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "----- Pdf Test -----" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
	
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
	
		ICharacter* bob = new Character("bob");
	
		me->use(0, *bob);
		me->use(1, *bob);
	
		delete bob;
		delete me;
		delete src;
	
	}
	std::cout << std::endl << "----- My Test -----" << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice()); //Equipement FULL
		src->learnMateria(new Cure()); //Equipement FULL

		ICharacter* me = new Character("me");
	
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("Shheeeshh"); //Materia doesnt exist
		me->equip(tmp);
	
		ICharacter* bob = new Character("bob");
	
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);

		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->use(2, *bob);		

		delete bob;
		delete me;
		delete src;
	}
	return 0;
}