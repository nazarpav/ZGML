#include "DotOperator.h"

DotOperator::DotOperator() :BaseZGMLOperator(".")
{
}
ZGMLOperatorReturnValue DotOperator::Action(const std::string& input, size_t& beginInput, size_t& endInput, std::string& subQuery, std::string& out)
{
	const std::string outError = "Not exist tag : " + subQuery;
	beginInput = input.find("<" + subQuery, beginInput);
	if (beginInput == std::string::npos)
	{
		out = outError;
		return ZGMLOperatorReturnValue::Error;
	}
	size_t endOfOpenTag = input.find(">", beginInput);
	endInput = input.find("</" + subQuery + ">", endOfOpenTag);
	if (endInput == std::string::npos)
	{
		out = outError;
		return ZGMLOperatorReturnValue::Error;
	}
	return ZGMLOperatorReturnValue::Next;
}
