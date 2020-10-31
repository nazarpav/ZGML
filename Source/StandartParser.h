#pragma once
#include<string>
#include <vector>
#include <memory>
#include"Parser.h"
#include"DotOperator.h"
#include"TildeOperator.h"
#include"BaseZGMLOperator.h"
class StandartParser
{
	const std::vector<std::shared_ptr<BaseZGMLOperator>> operators;
	const std::shared_ptr<BaseZGMLOperator> defaulthOperator;
	Parser _parser;
public:
	StandartParser();
	const std::string parse(const std::string& inputData, const std::string& query, ZGMLOperatorReturnValue& resultIdentificator, const bool isAllowWhiteSpaceInQuery) const;
};

