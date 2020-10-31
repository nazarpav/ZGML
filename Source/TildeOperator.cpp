#include "TildeOperator.h"

TildeOperator::TildeOperator() :BaseZGMLOperator("~")
{
}

ZGMLOperatorReturnValue TildeOperator::Action(const std::string& input, size_t& beginInput, size_t& endInput, std::string& subQuery, std::string& out)
{
	const std::string beginSymbol("\"");
	const std::string endSymbol("\"");
	//const std::string outErrorMessage("\"" + subQuery + "\" attribute does not exist.");
	const std::string outErrorMessage("Not Found!");
	const std::string trimedInput = input.substr(beginInput, endInput - beginInput);
	size_t localBeginInput;
	size_t localEndInput;
	localBeginInput = trimedInput.find(" " + subQuery + " ");
	if (localBeginInput == std::string::npos) {
		out = outErrorMessage;
		return ZGMLOperatorReturnValue::Error;
	}
	localBeginInput = trimedInput.find(beginSymbol, localBeginInput);
	if (localBeginInput == std::string::npos) {
		out = outErrorMessage;
		return ZGMLOperatorReturnValue::Error;
	}
	localEndInput = trimedInput.find(endSymbol, localBeginInput + beginSymbol.size());
	if (localBeginInput == std::string::npos) {
		out = outErrorMessage;
		return ZGMLOperatorReturnValue::Error;
	}
	out = trimedInput.substr(localBeginInput + beginSymbol.size(), localEndInput - localBeginInput - beginSymbol.size());
	return ZGMLOperatorReturnValue::Exit;
}

const bool TildeOperator::trimTagToEnd(std::string& input, const std::string& subQuery, const std::string beginSymbol, const std::string endSymbol, std::string& error)
{
	const std::string _error = "Syntax error";
	size_t endTagIndex = input.find(">");
	if (endTagIndex == std::string::npos) {
		error = _error;
		return false;
	}
	std::string tmpInput = input.substr(0, endTagIndex);
	size_t lastSymbolIndex = 0;
	bool flag = false;
	while (true)
	{
		lastSymbolIndex = tmpInput.find(beginSymbol, lastSymbolIndex == 0 ? 0 : lastSymbolIndex + beginSymbol.size());
		if (lastSymbolIndex == std::string::npos) {
			if (tmpInput.find(endSymbol, lastSymbolIndex) == std::string::npos) {
				break;
			}
			else {
				if (flag)
				{
					error = _error;
					return false;
				}
				flag = true;
			}
		}
		else {
			lastSymbolIndex = tmpInput.find(endSymbol, lastSymbolIndex + beginSymbol.size());
			if (lastSymbolIndex == std::string::npos) {
				error = _error;
				return false;
			}
			else {
				continue;
			}
		}
		size_t s = input.find(" " + subQuery + " ");
		input = input.substr(0, endTagIndex);
	}
	return true;
}

const size_t TildeOperator::findBeginAttributeIndex(const std::string& input, const std::string attribute)
{
	size_t index = input.find(" " + attribute + " ");
	if (index == std::string::npos)
		index = input.find(" " + attribute + "=");
	return index;
}

const std::pair<std::string, bool> TildeOperator::getAttributeValue(const std::string& input, const size_t& beginAttributeIndex, const std::string beginSymbol, const std::string endSymbol)
{
	size_t beginIndex;
	size_t endIndex;
	size_t index = input.find_first_not_of(" ", beginAttributeIndex);
	if (input[index] == '=') {
		++index;
		index = input.find_first_not_of(" ", index);
		if (input.substr(index, index + beginSymbol.size()) == beginSymbol) {
			beginIndex = index;
			endIndex = input.find(endSymbol, index + beginSymbol.size());
		}
		else {
			return std::make_pair<std::string, bool>("Syntax error", false);
		}
	}
	else {
		return std::make_pair<std::string, bool>("Syntax error", false);
	}
	return std::make_pair<std::string, bool>(input.substr(beginIndex + beginSymbol.size(), endIndex - beginIndex - endSymbol.size()), true);
}
