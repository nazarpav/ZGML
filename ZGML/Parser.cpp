#include "Parser.h"
const bool Parser::IsParameterCorrect(const std::string inputData, const std::string query, const std::vector<std::shared_ptr<BaseZGMLOperator>>& operators, const std::shared_ptr<BaseZGMLOperator>& defaulthOperator, std::string& error)
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

std::string Parser::parse(const std::string inputData, const std::string query, std::vector<std::shared_ptr<BaseZGMLOperator>>& operators, std::shared_ptr<BaseZGMLOperator>& defaulthOperator)
{
	std::string out;
	if (!IsParameterCorrect(inputData, query, operators, defaulthOperator, out))
	{
		return out;
	}
	size_t beginInput = 0u;
	size_t endInput = inputData.size();
	size_t beginSubQuery = 0u;
	size_t endSubQuery = 0u;
	std::shared_ptr<BaseZGMLOperator>  currentOperator;
	std::string subQuery;
	size_t firstOperatorIndex;
	while (true)
	{
		currentOperator = findFirstOperator(query, beginSubQuery, operators, firstOperatorIndex);
		if (firstOperatorIndex == std::string::npos)return "";
		beginSubQuery = firstOperatorIndex;
		findFirstOperator(query, beginSubQuery + currentOperator->getSymbol().size(), operators, firstOperatorIndex);
		endSubQuery = firstOperatorIndex == std::string::npos ? query.size() : firstOperatorIndex;
		subQuery = query.substr(beginSubQuery + currentOperator->getSymbol().size(), endSubQuery - beginSubQuery - currentOperator->getSymbol().size());
		switch (currentOperator->Action(inputData, beginInput, endInput, subQuery, out))
		{
		case ZGMLOperatorReturnValue::Error:
			return out;
			break;
		case ZGMLOperatorReturnValue::Exit:
			return out;
			break;
		case ZGMLOperatorReturnValue::Next:
			break;
		}
		beginSubQuery = endSubQuery;
	}
}
