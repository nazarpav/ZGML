#pragma once
#include<string>
#include <vector>
#include <memory>
#include<sstream>
#include"Parser.h"
#include"DotOperator.h"
#include"TildeOperator.h"
#include"BaseZGMLOperator.h"
#include"ZGMLOperatorReturnValue.h"

class StandartParser
{
	const std::vector<std::shared_ptr<BaseZGMLOperator>> operators;
	const std::shared_ptr<BaseZGMLOperator> defaulthOperator;
	Parser _parser;
public:
	StandartParser();
	const bool checkRestrictions(std::string& error, const std::string& inputData, std::string _query, const bool& isAllowWhiteSpaceInQuery);
	const std::string parse(const std::string& inputData, const std::string& query, ZGMLOperatorReturnValue& resultIdentificator, const bool& isAllowWhiteSpaceInQuery, const bool& isEnableRestrictions);
};

