#pragma once
#include"BaseZGMLOperator.h"
#include"ZGMLOperatorReturnValue.h"
#include <vector>
#include <memory>
#include<algorithm>
class Parser
{
private:
	const bool CheckIsQueryBeginFromOperator(const std::string& query, const std::vector<std::shared_ptr<BaseZGMLOperator>>& operators)const;
	const bool IsParameterCorrect(const std::string inputData, const std::string query, const std::vector<std::shared_ptr<BaseZGMLOperator>>& operators, const std::shared_ptr<BaseZGMLOperator>& defaulthOperator, std::string& error)const;
	const std::shared_ptr<BaseZGMLOperator> findFirstOperator(const std::string& query, const size_t& begin, const std::vector<std::shared_ptr<BaseZGMLOperator>>& operators, size_t& firstOperatorIndex)const;
public:
	const std::string parse(const std::string& inputData, const std::string& query, const std::vector<std::shared_ptr<BaseZGMLOperator>>& operators, const std::shared_ptr<BaseZGMLOperator>& defaulthOperator, ZGMLOperatorReturnValue& resultIdentificator, const bool isAllowWhiteSpaceInQuery)const;
};