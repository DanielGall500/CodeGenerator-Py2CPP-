#pragma once

#include <vector>
#include <string>

class Parser
{

public:
	Parser();
	~Parser();

	void Parse(std::vector<char> &input, std::vector<char> output);

private:
	std::vector<std::string> wordBuffer;
	std::vector<std::string> generatedCode;

    std::string generatePRINT(std::string strToPrint);
	int findEl(std::string element);

	const std::string commandPrint = "PRINT";


};

