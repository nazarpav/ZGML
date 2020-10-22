#include "StandartParser.h"

StandartParser::StandartParser() :
	defaulthOperator(std::make_shared<DotOperator>()),
	operators
	({
	std::make_shared<DotOperator>(),
	std::make_shared<TildeOperator>()
		})
{
}

std::string StandartParser::parse(std::string inputData, std::string query)
{
	return _parser.parse(inputData, query, operators, defaulthOperator);
}
