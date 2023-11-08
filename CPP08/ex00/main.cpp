#include "easyfind.hpp"

int main()
{

	// vector
	std::vector<int> array;
	array.push_back(10);
	array.push_back(20);
	array.push_back(30);
	array.push_back(40);
	array.push_back(50);
	try
	{
		int index_array = easyfind(array, 30);
		std::cout << "index : " << index_array << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	// list
	std::list<int> array_list;
	array_list.push_back(100);
	array_list.push_back(200);
	array_list.push_back(300);
	array_list.push_back(400);
	array_list.push_back(500);
	try
	{
		int index_list = easyfind(array_list, 600);
		std::cout << "index : " << index_list << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}