#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <utility>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <sys/time.h>

class	PmergeMe
{
	private:
	std::vector<int>					VecArray;
	std::deque<int>						DecArray;

	std::clock_t						timeofstart;
	std::clock_t						timeofcheck;
	std::clock_t						timeofVec;
	std::clock_t						timeofDec;

	PmergeMe(const PmergeMe& others);
	PmergeMe& operator=(const PmergeMe& others);

	public:
	PmergeMe();
	~PmergeMe();

	void					CheckArg(int ac, char **av);
	void					startTime();
	void					CheckTime();
	void					VecTime();
	void					DecTime();

	void					printResult();
	void					printVecTime();
	void					printDecTime();


	std::vector<int>		Jacobsthal(int num);
	std::deque<int>			JacobsthalDec(int num);
	int						getrange(int num);
	int						Pow(int num);

	void					FordJohnsonVec();
	void					MergeInsert(unsigned int n_size);
	void					InsertSort(unsigned int n_size);
	int						binarysearch(int right, int value, int n_size);

	void					FordJohnsonDec();
	void					MergeInsertDec(unsigned int n_size);
	void					InsertSortDec(unsigned int n_size);
	int						binarysearchDec(int right, int value, int n_size);

};
#endif