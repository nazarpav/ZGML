#include "TildeOperator.h"

TildeOperator::TildeOperator() :BaseZGMLOperator("~")
{
}

ZGMLOperatorReturnValue TildeOperator::Action(const std::string& input, size_t& beginInput, size_t& endInput, std::string& subQuery, std::string& out)
{
	const std::string beginSymbol("\"");
	const std::string endSymbol("\"");
	const std::string outErrorMessage("\"" + subQuery + "\" attribute does not exist.");
	size_t localBeginInput;
	size_t localEndInput;
	localBeginInput = input.find(" "+subQuery+" ");
	if (localBeginInput == std::string::npos){
		out = outErrorMessage;
		return ZGMLOperatorReturnValue::Error;
	}
	localBeginInput = input.find(beginSymbol, localBeginInput);
	if (localBeginInput == std::string::npos) {
		out = outErrorMessage;
		return ZGMLOperatorReturnValue::Error;
	}
	localEndInput = input.find(endSymbol, localBeginInput + beginSymbol.size());
	if (localBeginInput == std::string::npos) {
		out = outErrorMessage;
		return ZGMLOperatorReturnValue::Error;
	}
	out = input.substr(localBeginInput + beginSymbol.size(), localEndInput - localBeginInput - beginSymbol.size());
	return ZGMLOperatorReturnValue::Exit;
}
