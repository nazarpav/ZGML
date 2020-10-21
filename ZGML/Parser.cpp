#include "Parser.h"

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

}
