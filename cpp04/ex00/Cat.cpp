#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const &src);
		~Animal();
		Animal	&operator=(Animal const &rhs);

}
