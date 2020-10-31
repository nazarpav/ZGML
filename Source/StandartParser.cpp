#include "StandartParser.h"
#include"ZGMLOperatorReturnValue.h"
StandartParser::StandartParser() :
	defaulthOperator(std::make_shared<DotOperator>()),
	operators
	({
	std::make_shared<DotOperator>(),
	std::make_shared<TildeOperator>()
		})
{
}

const std::string StandartParser::parse(const std::string& inputData, const std::string& query, ZGMLOperatorReturnValue& resultIdentificator, const bool isAllowWhiteSpaceInQuery) const
{
	return _parser.parse(inputData, query, operators, defaulthOperator, resultIdentificator, isAllowWhiteSpaceInQuery);
}
