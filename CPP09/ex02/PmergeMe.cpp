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


// time 체크 함수
void	PmergeMe::startTime()
{
	timeofstart = std::clock();
}

void	PmergeMe::CheckTime()
{
	timeofcheck = std::clock();
}

void	PmergeMe::VecTime()
{
	timeofVec = std::clock();	
}

void	PmergeMe::DecTime()
{
	timeofDec = std::clock();	
}


// print함수
void	PmergeMe::printVecTime()
{
	double time = static_cast<double>(timeofVec - timeofstart) / CLOCKS_PER_SEC * 1e1;
	std::cout << "Time to process a range of " << VecArray.size() << " elements with std::vector : "\
	<< time << " us" << std::endl;
}

void	PmergeMe::printDecTime()
{
	double time = static_cast<double>(timeofDec - timeofstart - (timeofVec - timeofcheck)) / CLOCKS_PER_SEC * 1e1;
	std::cout << "Time to process a range of " << DecArray.size() << " elements with std::deque : "\
	<< time << " us" << std::endl;
}

void				PmergeMe::printResult()
{
	unsigned int size = VecArray.size();
	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << VecArray[i] << " ";
	}
	std::cout << "\n";
}


// 인자 확인 및 저장
void	PmergeMe::CheckArg(int ac, char **av)
{
	if (ac == 2)
		throw std::invalid_argument("Error");
	for (int i = 1; i < ac; i++)
	{
		std::string str(av[i]);
		for(unsigned long j = 0; j < str.size(); j++)
		{
			if (!isdigit(str[j]))
				throw std::invalid_argument("Error");
		}
		if (str.size() > 10)
			throw std::out_of_range("Error");
		char *endptr;
		double result = std::strtod(av[i], &endptr);
		if (result > 2147483647 || result < 0)
			throw std::out_of_range("Error");
		int value = static_cast<int>(result);
		if (std::find(VecArray.begin(), VecArray.end(), value) != VecArray.end())
			throw std::invalid_argument("duplicate input is not allowed");
		VecArray.push_back(value);
		DecArray.push_back(value);
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

std::deque<int>	PmergeMe::JacobsthalDec(int num)
{
	std::deque<int>	Jacob;
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
	std::deque<int>	JacobIndex;
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


int		PmergeMe::getrange(int num)
{
	return pow(2, static_cast<int>(log2(num) + 1)) - 1;
}



// vecto로 정렬
int	PmergeMe::binarysearch(int right, int value, int n_size)
{
	int left = 0;
	if (right == 0)
		return (0);
	while (left <= right)
	{
		int mid = (left + (right - left) / 2) * n_size;
		if (n_size == 1 && value == 63)
		{
			std::cout << "\n---------------------\n";
			std::cout << "left == " << left << " right == " << right << " mid == " << mid << std::endl;
		}
		if (VecArray[mid] < value)
			left = mid / n_size + 1;
		else
			right = mid / n_size - 1;
	}
	if (left < 0)
		return (0);
	return left * n_size;
}

void	PmergeMe::InsertSort(unsigned int n_size)
{
	unsigned int size = VecArray.size();
	unsigned int Node_cnt = size / n_size;

	unsigned int a_cnt = Node_cnt / 2;
	unsigned int b_cnt = Node_cnt / 2 + Node_cnt % 2;

	std::vector<int>	pend;
	for (unsigned int k = 1; k <= a_cnt; k++)
	{
		std::vector<int>::iterator a_firstitr = VecArray.begin();
		std::vector<int>::iterator a_lastitr = VecArray.begin();
		std::vector<int>::iterator b_itr = pend.end();
		std::advance(a_firstitr, n_size * k);
		std::advance(a_lastitr, n_size * (k + 1));
		pend.insert(b_itr, a_firstitr, a_lastitr);
		VecArray.erase(a_firstitr, a_lastitr);
	}
	if (a_cnt < b_cnt)
	{
		std::vector<int>::iterator a_firstitr = VecArray.begin();
		std::vector<int>::iterator a_lastitr = VecArray.begin();
		std::vector<int>::iterator b_itr = pend.end();
		std::advance(a_firstitr, n_size * a_cnt);
		std::advance(a_lastitr, n_size * (a_cnt + 1));
		pend.insert(b_itr, a_firstitr, a_lastitr);
		VecArray.erase(a_firstitr, a_lastitr);
	}
	
	std::cout << "\nn_size == " << n_size << std::endl;
	std::cout << "a == ";
	for (unsigned int k = 0; k < VecArray.size(); k++)
	{
		std::cout << VecArray[k] << " ";
	}
	std::cout << "\n\n";

	std::cout << "b == ";
	for (unsigned int k = 0; k < pend.size(); k++)
	{
		std::cout << pend[k] << " ";
	}
	std::cout << "\n\n";
	std::vector<int> jacopIndex = Jacobsthal(b_cnt);

	for (unsigned int n = 0; n < b_cnt; n++)
	{
		int index = (jacopIndex[n] - 1) * n_size;
		if (n == 9)
		{
			std::cout << "\n --------\n";
			std::cout << index << std::endl;
		}
		std::vector<int>::iterator maxindex = pend.begin();
		std::advance(maxindex, index);
		int find = binarysearch(getrange(jacopIndex[n]), *maxindex, n_size);
		std::vector<int>::iterator inputItr = VecArray.begin();
		std::advance(inputItr, find);
		std::vector<int>::iterator b_startItr = pend.begin();
		std::advance(b_startItr, index);
		std::vector<int>::iterator b_endItr = b_startItr;
		std::advance(b_endItr, n_size);
		if (n_size == 1 && index == 6)
		{
			std::cout << "\n -------check--------\n";
			std::cout << "n == " << n << std::endl;
			std::cout << find << std::endl;
			for (unsigned int m = 0; m < VecArray.size(); m++)
			{
				std::cout << VecArray[m] << " ";
			}
			std::cout << "\n";
		}
		VecArray.insert(inputItr, b_startItr, b_endItr);
	}
	std::cout << "\n----binary insert ----- n_size == " << n_size << std::endl;
	for (unsigned int k = 0; k < size; k++)
	{
		std::cout << VecArray[k] << " ";
	}
	std::cout << "\n";
}

void	PmergeMe::MergeInsert(unsigned int n_size)
{
	unsigned int size = VecArray.size();
	for (unsigned int i = 0; i < size; i += (n_size * 2))
	{
		if ((i + (n_size * 2)) <= size && VecArray[i] < VecArray[i + n_size])
		{
			for (unsigned int j = i; j < i + n_size; j++)
			{
				std::swap(VecArray[j], VecArray[j + n_size]);
			}
		}
	}
	std::cout << "\n----mergeInsert ----- n_size == " << n_size << std::endl;
	for (unsigned int k = 0; k < size; k++)
	{
		std::cout << VecArray[k] << " ";
	}
	std::cout << "\n";
	if (n_size * 4 < size)
	{
		MergeInsert(n_size * 2);
	}
	InsertSort(n_size);
}

void	PmergeMe::FordJohnsonVec()
{
	MergeInsert(1);
	VecTime();
}



// deque로 정렬
int	PmergeMe::binarysearchDec(int right, int value, int n_size)
{
	int left = 0;
	if (right == 0)
		return (0);
	while (left <= right)
	{
		int mid = (left + (right - left) / 2) * n_size;
	
		if (DecArray[mid] < value)
			left = mid + n_size;
		else
			right = mid - n_size;
	}
	return left;
}

void	PmergeMe::InsertSortDec(unsigned int n_size)
{
	unsigned int size = DecArray.size();
	unsigned int Node_cnt = size / n_size;

	unsigned int a_cnt = Node_cnt / 2;
	unsigned int b_cnt = Node_cnt / 2 + Node_cnt % 2;

	std::deque<int>	pend;
	for (unsigned int k = 1; k <= a_cnt; k++)
	{
		std::deque<int>::iterator a_firstitr = DecArray.begin();
		std::deque<int>::iterator a_lastitr = DecArray.begin();
		std::deque<int>::iterator b_itr = pend.end();
		std::advance(a_firstitr, n_size * k);
		std::advance(a_lastitr, n_size * (k + 1));
		pend.insert(b_itr, a_firstitr, a_lastitr);
		DecArray.erase(a_firstitr, a_lastitr);
	}
	if (a_cnt < b_cnt)
	{
		std::deque<int>::iterator a_firstitr = DecArray.begin();
		std::deque<int>::iterator a_lastitr = DecArray.begin();
		std::deque<int>::iterator b_itr = pend.end();
		std::advance(a_firstitr, n_size * a_cnt);
		std::advance(a_lastitr, n_size * (a_cnt + 1));
		pend.insert(b_itr, a_firstitr, a_lastitr);
		DecArray.erase(a_firstitr, a_lastitr);
	}

	std::deque<int> jacopIndex = JacobsthalDec(b_cnt);
	for (unsigned int n = 0; n < b_cnt; n++)
	{
		int index = (jacopIndex[n] - 1) * n_size;
		std::deque<int>::iterator maxindex = pend.begin();
		std::advance(maxindex, index);
		int find = binarysearchDec(getrange(jacopIndex[n]) - 1, *maxindex, n_size);
		std::deque<int>::iterator inputItr = DecArray.begin();
		std::advance(inputItr, find);
		std::deque<int>::iterator b_startItr = pend.begin();
		std::advance(b_startItr, index);
		std::deque<int>::iterator b_endItr = b_startItr;
		std::advance(b_endItr, n_size);
		DecArray.insert(inputItr, b_startItr, b_endItr);
	}
}

void	PmergeMe::MergeInsertDec(unsigned int n_size)
{
	unsigned int size = DecArray.size();
	for (unsigned int i = 0; i < size; i += (n_size * 2))
	{
		if ((i + (n_size * 2)) <= size && DecArray[i] < DecArray[i + n_size])
		{
			for (unsigned int j = i; j < i + n_size; j++)
			{
				std::swap(DecArray[j], DecArray[j + n_size]);
			}
		}
	}
	if (n_size * 4 <= size)
	{
		MergeInsertDec(n_size * 2);
	}
	InsertSortDec(n_size);
}

void	PmergeMe::FordJohnsonDec()
{
	MergeInsertDec(1);
	DecTime();
}
