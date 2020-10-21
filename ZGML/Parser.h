#pragma once
#include"BaseZGMLOperator.h"
#include <vector>
#include <memory>
class Parser
{
private:
	const std::shared_ptr<BaseZGMLOperator> findFirstOperator(const std::string& query, const size_t& begin, const std::vector<std::shared_ptr<BaseZGMLOperator>>& operators, size_t& firstOperatorIndex)const;
public:
	std::string parse(const std::string inputData, const std::string query, std::vector<std::shared_ptr<BaseZGMLOperator>>& specialSymbols, std::shared_ptr<BaseZGMLOperator>& defaulthSymbol);
};