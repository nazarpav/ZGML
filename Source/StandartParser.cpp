#include "StandartParser.h"
StandartParser::StandartParser() :
	defaulthOperator(std::make_shared<DotOperator>()),
	operators
	({
	std::make_shared<DotOperator>(),
	std::make_shared<TildeOperator>()
		})
{
}
const bool StandartParser::checkRestrictions(std::string& error, const std::string& inputData, std::string _query, const bool& isAllowWhiteSpaceInQuery)
{
	const size_t N_MAX = 20;
	const size_t N_MIN = 1;
	const size_t INPUT_DATA_STRING_MAX_LENGTH = 200;
	const size_t QUERY_STRING_MAX_LENGTH = 200;
	if (isAllowWhiteSpaceInQuery)
		_query.erase(remove(_query.begin(), _query.end(), ' '), _query.end());
	if (_query.size() > QUERY_STRING_MAX_LENGTH) {
		error = "QUERY_STRING_MAX_LENGTH is " + std::to_string(QUERY_STRING_MAX_LENGTH) + ", now lenght is " + std::to_string(_query.size());
		return false;
	}
	std::istringstream iss(inputData);
	std::string line;
	size_t counter = 0;
	while (std::getline(iss, line)) {
		++counter;
		if (line.size() > INPUT_DATA_STRING_MAX_LENGTH) {
			error = "INPUT_DATA_STRING_MAX_LENGTH is " + std::to_string(INPUT_DATA_STRING_MAX_LENGTH) + ", now lenght is " + std::to_string(line.size());
			return false;
		}
	}
	if (counter > N_MAX) {
		error = "N max string quantity is " + std::to_string(N_MAX) + ", current quantity is " + std::to_string(counter);
		return false;
	}
	else if (counter < N_MIN) {
		error = "N min string quantity is " + std::to_string(N_MIN) + ", current quantity is " + std::to_string(counter);
		return false;
	}
	return true;
}
const std::string StandartParser::parse(const std::string& inputData, const std::string& query, ZGMLOperatorReturnValue& resultIdentificator, const bool& isAllowWhiteSpaceInQuery, const bool& isEnableRestrictions)
{
	if (isEnableRestrictions) {
		std::string error;
		if (!checkRestrictions(error, inputData, query, isEnableRestrictions)) {
			resultIdentificator = ZGMLOperatorReturnValue::Error;
			return error;
		}
	}
	return _parser.parse(inputData, query, operators, defaulthOperator, resultIdentificator, isAllowWhiteSpaceInQuery);
}
