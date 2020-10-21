#include "DotOperator.h"

DotOperator::DotOperator() :BaseZGMLOperator(".")
{
}

bool DotOperator::Action(const std::string& input, size_t& beginInput, size_t& endInput, std::string& subQuery)
{
	beginInput = input.find(("<" + subQuery).c_str(), beginInput, endInput - beginInput);
	endInput = input.find(("</" + subQuery + ">").c_str(), beginInput, endInput - beginInput);
	return true;
}
