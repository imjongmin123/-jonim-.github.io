#ifndef WARLOCK_HPP
#define WARLOCK_HPP
#include <iostream>

class Warlock
{
	private:
	std::string name;
	std::string title;
	Warlock();
	Warlock(const Warlock& others);
	Warlock& operator=(const Warlock& others);

	public:
	~Warlock();
	Warlock(std::string name_, std::string title_);
	const std::string& getName() const;
	const std::string& getTitle() const;
	void			   setTitle(const std::string& title_);
	void 			   introduce() const;
};

#endif
