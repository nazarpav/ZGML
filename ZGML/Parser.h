#pragma once
#include"BaseZGMLOperator.h"
#include"ZGMLOperatorReturnValue.h"
#include <vector>
#include<iostream>
#include <memory>
class Parser
{
private:
	const bool IsParameterCorrect(const std::string inputData, const std::string query, const std::vector<std::shared_ptr<BaseZGMLOperator>>& operators, const std::shared_ptr<BaseZGMLOperator>& defaulthOperator, std::string& error);
	const std::shared_ptr<BaseZGMLOperator> findFirstOperator(const std::string& query, const size_t& begin, const std::vector<std::shared_ptr<BaseZGMLOperator>>& operators, size_t& firstOperatorIndex)const;
public:
	std::string parse(const std::string inputData, const std::string query, std::vector<std::shared_ptr<BaseZGMLOperator>>& specialSymbols, std::shared_ptr<BaseZGMLOperator>& defaulthSymbol);
};