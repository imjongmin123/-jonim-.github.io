#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
	MutantStack()
	{
	};
	~MutantStack() {};
	MutantStack(const MutantStack& others) {
		if (this == &others)
			return ;
	};
	MutantStack& operator=(const MutantStack& others) {
		if (this == &others)
			return *this;
		return *this;
	};

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
};

#endif