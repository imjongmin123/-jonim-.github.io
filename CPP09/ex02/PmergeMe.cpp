#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& others)
{
	if (this == &others)
		return ;
}
PmergeMe& PmergeMe::operator=(const PmergeMe& others)
{
	if (this == &others)
		return *this;
	return (*this);
}

void	PmergeMe::CheckArg(int ac, char **av)
{
	if (ac == 1 || ac > 3001)
		throw std::invalid_argument("input number error");
	for (int i = 1; i < ac; i++)
	{
		std::string str(av[i]);
		for(unsigned long j = 0; j < str.size(); j++)
		{
			if (!isdigit(str[j]))
				throw std::invalid_argument("input error");
		}
		if (str.size() > 10)
			throw std::out_of_range("int overflow");
		char *endptr;
		double result = std::strtod(av[i], &endptr);
		if (result > 2147483647 || result < 0)
			throw std::out_of_range("invalid range");
		int value = static_cast<int>(result);
		if (std::find(VecArray.begin(), VecArray.end(), value) != VecArray.end())
			throw std::invalid_argument("duplicate input is not allowed");
		VecArray.push_back(value);
	}
}

int					PmergeMe::Pow(int num)
{
	if (num == 0)
		return (1);
	int i = 1;
	int ret = 1;
	while (i <= num)
	{
		ret = ret * 2;
		i++;
	}
	return (ret);
}

std::vector<int>	PmergeMe::Jacobsthal(int num)
{
	std::vector<int>	Jacob;
	Jacob.push_back(1);
	int i = 2;
	while (1)
	{
		if (Pow(i) - Jacob.back() <= num)
			Jacob.push_back(Pow(i) - Jacob.back());
		else
			break ;
		i++;
	}
	std::vector<int>	JacobIndex;
	JacobIndex.push_back(1);
	unsigned int size = Jacob.size();
	for (unsigned int i = 1; i < size; i++)
	{
		int pre = Jacob[i - 1];
		int value = Jacob[i];
		while (value > pre)
		{
			JacobIndex.push_back(value);
			value--;
		}
	}
	int max = Jacob.back();
	while (num > max)
	{
		JacobIndex.push_back(num);
		num--;
	}
	return (JacobIndex);
}

void	PmergeMe::Insertion()
{

}

int		PmergeMe::BinarySearch(std::vector<int>& arr, int value, int left, int right)
{
	int idx = 0;
	int n = arr.size();
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] < value)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return (left);
}



void	PmergeMe::Merge(std::vector<std::pair<int, int>>& pair, std::vector<int>& mainchain)
{
	
}


void	PmergeMe::FordJohnson(std::vector<int>& arr, int left, int right)
{
	if (left >= right)
		return ;
	std::vector<int>	mainchain;
	std::vector<int>	pending;
	std::vector<std::pair<int, int>>	pair;
	unsigned int i = 0;
	unsigned int size = arr.size();
	while (i < size)
	{
		if (i + 1 < size)
		{
			if (arr[i] > arr[i + 1])
			{
				mainchain.push_back(arr[i]);
				pending.push_back(arr[i + 1]);
			}
			else
			{
				mainchain.push_back(arr[i + 1]);
				pending.push_back(arr[i]);
			}
			pair.push_back(std::pair<int, int>{mainchain.back(), pending.back()});
			i++;
		}
		else
		{
			pending.push_back(arr[i]);
			break ;
		}
		i++;
	}
	FordJohnson(mainchain, 0, mainchain.size() - 1);
	Merge(pair, mainchain);
}


std::vector<int>	PmergeMe::getVec()
{
	return (VecArray);
}