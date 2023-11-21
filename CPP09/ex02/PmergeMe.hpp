#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <utility>

#define FAIL 1
#define SUCCESS 1

class	PmergeMe
{
	private:
	std::vector<int>					VecArray;
	PmergeMe(const PmergeMe& others);
	PmergeMe& operator=(const PmergeMe& others);

	public:
	PmergeMe();
	~PmergeMe();

	void				CheckArg(int ac, char **av);
	void				FordJohnson(std::vector<int>& arr, int left, int right);
	void				Merge(std::vector<std::pair<int, int>>& pair, std::vector<int>& mainchain);
	int					BinarySearch(std::vector<int>& arr, int value, int left, int right);
	void				Insertion();
	std::vector<int>	Jacobsthal(int num);
	

	std::vector<int>	getVec();
	int					Pow(int num);
};

#endif
