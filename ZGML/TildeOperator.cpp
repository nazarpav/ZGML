#include "TildeOperator.h"

TildeOperator::TildeOperator() :BaseZGMLOperator("~")
{
}

bool TildeOperator::Action(const std::string& input, size_t& beginInput, size_t& endInput, std::string& subQuery)
{
	return false;
}
