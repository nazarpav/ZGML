#include "DotOperator.h"

DotOperator::DotOperator() :BaseZGMLOperator(".")
{
}
ZGMLOperatorReturnValue DotOperator::Action(const std::string& input, size_t& beginInput, size_t& endInput, std::string& subQuery, std::string& out)
{
	std::string input_ = input.substr(beginInput, endInput - beginInput);
	beginInput = input_.find("<" + subQuery);
	if (beginInput != std::string::npos)
	{
		input_ = input.substr(beginInput, endInput - beginInput);
		endInput = input_.find("</" + subQuery + ">");
	}
	if (beginInput == std::string::npos || endInput == std::string::npos)
	{
		out = "Not exist tag : " + subQuery;
		return ZGMLOperatorReturnValue::Error;
	}
	return ZGMLOperatorReturnValue::Next;
}
