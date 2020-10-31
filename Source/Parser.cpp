#include "Parser.h"
const bool Parser::CheckIsQueryBeginFromOperator(const std::string& query, const std::vector<std::shared_ptr<BaseZGMLOperator>>& operators)const
{
	size_t firstOperatorIndex;
	findFirstOperator(query, 0, operators, firstOperatorIndex);
	return firstOperatorIndex != 0;
}
const bool Parser::IsParameterCorrect(const std::string inputData, const std::string query, const std::vector<std::shared_ptr<BaseZGMLOperator>>& operators, const std::shared_ptr<BaseZGMLOperator>& defaulthOperator, std::string& error)const
{
	if (inputData.size() == 0)
	{
		error = "input must not be empty";
		return false;
	}
	else if (query.size() == 0)
	{
		error = "query must not be empty";
		return false;
	}
	else if (operators.size() == 0)
	{
		error = "operators must not be empty";
		return false;
	}
	else if (defaulthOperator.get() == nullptr)
	{
		error = "defaulthOperator must not be empty";
		return false;
	}
	error = std::string::npos;
	return true;
}
const std::shared_ptr<BaseZGMLOperator> Parser::findFirstOperator(const std::string& query, const size_t& begin, const std::vector<std::shared_ptr<BaseZGMLOperator>>& operators, size_t& firstOperatorIndex)const
{
	firstOperatorIndex = query.size();
	size_t currentOperatorIndex;
	std::shared_ptr<BaseZGMLOperator> firstOperator;
	for (size_t i = 0; i < operators.size(); i++)
	{
		currentOperatorIndex = query.find(operators[i]->getSymbol(), begin);
		if (currentOperatorIndex < firstOperatorIndex)
		{
			firstOperatorIndex = currentOperatorIndex;
			firstOperator = operators[i];
		}
	}
	if (firstOperator.get() == nullptr)firstOperatorIndex = std::string::npos;
	return firstOperator;
}

const std::string Parser::parse(const std::string& inputData, const std::string& _query, const std::vector<std::shared_ptr<BaseZGMLOperator>>& operators, const std::shared_ptr<BaseZGMLOperator>& defaulthOperator, ZGMLOperatorReturnValue& resultIdentificator, const bool isAllowWhiteSpaceInQuery)const
{
	std::string out = "";
	std::string query = _query;
	if (!IsParameterCorrect(inputData, query, operators, defaulthOperator, out)) {
		resultIdentificator = ZGMLOperatorReturnValue::Error;
		return std::move(out);
	}
	size_t beginInput = 0u;
	size_t endInput = inputData.size();
	size_t beginSubQuery = 0u;
	size_t endSubQuery = 0u;
	std::shared_ptr<BaseZGMLOperator>  currentOperator;
	std::string subQuery;
	size_t firstOperatorIndex;
	if (CheckIsQueryBeginFromOperator(query, operators))
		query = defaulthOperator->getSymbol() + query;
	while (true)
	{
		currentOperator = findFirstOperator(query, beginSubQuery, operators, firstOperatorIndex);
		if (firstOperatorIndex == std::string::npos) {
			resultIdentificator = ZGMLOperatorReturnValue::Error;
			return "Undefined behavior";
		}
		beginSubQuery = firstOperatorIndex;
		findFirstOperator(query, beginSubQuery + currentOperator->getSymbol().size(), operators, firstOperatorIndex);
		endSubQuery = firstOperatorIndex == std::string::npos ? query.size() : firstOperatorIndex;
		subQuery = query.substr(beginSubQuery + currentOperator->getSymbol().size(), endSubQuery - beginSubQuery - currentOperator->getSymbol().size());
		if (isAllowWhiteSpaceInQuery)
			subQuery.erase(remove(subQuery.begin(), subQuery.end(), ' '), subQuery.end());
		else if (subQuery.find(' ') != std::string::npos) {
			resultIdentificator = ZGMLOperatorReturnValue::Warning;
			return "Not Found!";
		}
		switch (currentOperator->Action(inputData, beginInput, endInput, subQuery, out))
		{
		case ZGMLOperatorReturnValue::Error:
			resultIdentificator = ZGMLOperatorReturnValue::Error;
			return std::move(out);
			break;
		case ZGMLOperatorReturnValue::Warning:
			resultIdentificator = ZGMLOperatorReturnValue::Warning;
			return std::move(out);
			break;
		case ZGMLOperatorReturnValue::CorrectExit:
			resultIdentificator = ZGMLOperatorReturnValue::CorrectExit;
			return std::move(out);
			break;
		case ZGMLOperatorReturnValue::Next:
			beginSubQuery = endSubQuery;
			continue;
			break;
		}
	}
}
