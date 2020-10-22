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
	std::string parse(std::string inputData, std::string query);
};

