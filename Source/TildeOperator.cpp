#include "TildeOperator.h"

TildeOperator::TildeOperator() :BaseZGMLOperator("~")
{
}

ZGMLOperatorReturnValue TildeOperator::Action(const std::string& input, size_t& beginInput, size_t& endInput, std::string& subQuery, std::string& out)
{
	const std::string beginSymbol("\"");
	const std::string endSymbol("\"");
	//const std::string outErrorMessage("\"" + subQuery + "\" attribute does not exist.");
	std::string outErrorMessage("Not Found!");
	std::string trimedInput = input.substr(beginInput, endInput - beginInput);
	if (!trimTagToEnd(trimedInput, outErrorMessage)) {
		return ZGMLOperatorReturnValue::Error;
	}
	size_t beginAttributeIndex = findBeginAttributeIndex(trimedInput, subQuery);
	if (beginAttributeIndex == std::string::npos) {
		out = outErrorMessage;
		return ZGMLOperatorReturnValue::Warning;
	}
	std::pair<std::string, bool> res = getAttributeValue(trimedInput, beginAttributeIndex + 1 + subQuery.size(), beginSymbol, endSymbol);
	out = res.first;
	return res.second ? ZGMLOperatorReturnValue::CorrectExit : ZGMLOperatorReturnValue::Error;
}

const bool TildeOperator::trimTagToEnd(std::string& input, std::string& error)const
{
	const std::string _error = "Syntax error!";
	size_t endTagIndex = input.find(">");
	if (endTagIndex == std::string::npos) {
		error = _error;
		return false;
	}
	input = input.substr(0u, endTagIndex);
	return true;
}

const size_t TildeOperator::findBeginAttributeIndex(const std::string& input, const std::string attribute)const
{
	size_t index = input.find(" " + attribute + " ");
	if (index == std::string::npos)
		index = input.find(" " + attribute + "=");
	return index;
}

const std::pair<std::string, bool> TildeOperator::getAttributeValue(const std::string& input, const size_t& endAttributeIndex, const std::string beginSymbol, const std::string endSymbol)const
{
	std::string _error = "Syntax error!";
	size_t beginIndex;
	size_t endIndex;
	size_t index = input.find_first_not_of(" ", endAttributeIndex);
	if (input[index] == '=') {
		++index;
		index = input.find_first_not_of(" ", index);
		if (input.substr(index, beginSymbol.size()) == beginSymbol) {
			beginIndex = index;
			endIndex = input.find(endSymbol, index + beginSymbol.size());
			if (endIndex == std::string::npos) {
				return std::make_pair<std::string, bool>(std::move(_error), false);
			}
		}
		else {
			return std::make_pair<std::string, bool>(std::move(_error), false);
		}
	}
	else {
		return std::make_pair<std::string, bool>(std::move(_error), false);
	}
	return std::make_pair<std::string, bool>(input.substr(beginIndex + beginSymbol.size(), endIndex - beginIndex - endSymbol.size()), true);
}
