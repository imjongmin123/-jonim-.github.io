#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP
#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
	private:
	std::map<std::string, ATarget*> target;
	TargetGenerator(const TargetGenerator& others);
	TargetGenerator& operator=(const TargetGenerator& others);

	public:
	TargetGenerator();
	~TargetGenerator();

	void	learnTargetType(ATarget* A_T);
	void	forgetTargetType(const std::string& type_);
	ATarget* createTarget(const std::string& type_);

};

#endif
