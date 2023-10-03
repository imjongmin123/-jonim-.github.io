#include <iostream>
#include <fstream>
#include <string>

int	main(int ac, char* av[])
{
	if (ac != 4)
	{
		std::cout << "invalid argument number" << std::endl;
		return (1);
	}
	int len = std::strlen(av[2]);
	std::ifstream readfile(av[1]);
	std::ofstream writefile(av[1] + std::string(".replace"));
	if (readfile.is_open() && writefile.is_open())
	{
		std::string line;
		while (getline(readfile, line))
		{
			int index = 0;
			if (av[2][0] != '\0')
			{
				while (line.find(av[2], index) != std::string::npos)
				{
					index = line.find(av[2], index);
					line.erase(index, len);
					line.insert(index, av[3]);
					index = index + std::strlen(av[3]);
				}
			}
			writefile << line;
			if (!readfile.eof())
			{
				writefile << std::endl;
			}
		}
		readfile.close();
		writefile.close();
	}
	else
	{
		std::cout << "can not open file" << std::endl;
	}
	return (0);
}
