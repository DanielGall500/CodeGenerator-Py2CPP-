#pragma once

#include <vector>

class Parser
{

public:
	Parser();
	~Parser();

	void Parse(std::vector<char> &input, std::vector<char> output);

private:
	std::vector<char> inputVector;

};

