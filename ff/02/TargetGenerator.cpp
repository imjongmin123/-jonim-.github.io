#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}
TargetGenerator::~TargetGenerator() {}
TargetGenerator::TargetGenerator(const TargetGenerator& others)
{
	if (this == &others)
		return ;
}
TargetGenerator& TargetGenerator::operator=(const TargetGenerator& others)
{
	if (this == &others)
		return *this;
	return *this;
}

void	TargetGenerator::learnTargetType(ATarget* A_T)
{
	if (target.find(A_T->getType()) != target.end())
		return ;
	target[A_T->getType()] = A_T->clone();
}

void	TargetGenerator::forgetTargetType(const std::string& type_)
{
	std::map<std::string, ATarget*>::iterator it = target.find(type_);
	if (it != target.end())
	{
		delete it->second;
		target.erase(it);
	}
}

ATarget* TargetGenerator::createTarget(const std::string& type_)
{
	std::map<std::string, ATarget*>::iterator it = target.find(type_);
	if (it != target.end())
	{
		return it->second->clone();
	}
	return NULL;
}