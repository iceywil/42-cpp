#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string str = argv[i];
			for (int x = 0; str[x]; x++)
				str[x] = std::toupper(str[x]);
			std::cout << str;
		}
		std::cout << std::endl;
	}
	return (0);
}
