#include "DotOperator.h"

DotOperator::DotOperator() :BaseZGMLOperator(".")
{
}
ZGMLOperatorReturnValue DotOperator::Action(const std::string& input, size_t& beginInput, size_t& endInput, std::string& subQuery, std::string& out)
{
	const std::string outError = "Not exist tag : \"" + subQuery + "\"";
	size_t firtTagIndex = beginInput;
	size_t firtTagIndexEnd;
	size_t firtTagIndexEnd2;
	while (true) {
		firtTagIndex = input.find("<", firtTagIndex);
		if (firtTagIndex == std::string::npos) {
			out = outError;
			return ZGMLOperatorReturnValue::Error;
		}
		firtTagIndexEnd = input.find(' ', firtTagIndex);
		if (firtTagIndex == std::string::npos) {
			out = outError;
			return ZGMLOperatorReturnValue::Error;
		}
		firtTagIndexEnd2 = input.find('>', firtTagIndex);
		if (firtTagIndex == std::string::npos) {
			out = outError;
			return ZGMLOperatorReturnValue::Error;
		}
		firtTagIndexEnd = firtTagIndexEnd > firtTagIndexEnd2 ? firtTagIndexEnd2 : firtTagIndexEnd;
		std::string tag = input.substr(firtTagIndex + 1, firtTagIndexEnd - firtTagIndex - 1);
		if (tag == subQuery) {
			beginInput = firtTagIndex + 1;
			break;
		}
		else {
			size_t saveEndInput = endInput;
			firtTagIndexEnd = input.find("</" + tag + ">", firtTagIndexEnd);
			if (firtTagIndexEnd == std::string::npos || firtTagIndexEnd > saveEndInput)
			{
				out = outError;
				return ZGMLOperatorReturnValue::Error;
			}
			firtTagIndex = firtTagIndexEnd+1;
		}
	}
	size_t saveEndInput = endInput;
	endInput = input.find("</" + subQuery + ">", beginInput);
	if (endInput == std::string::npos || endInput > saveEndInput)
	{
		out = outError;
		return ZGMLOperatorReturnValue::Error;
	}
	return ZGMLOperatorReturnValue::Next;
}