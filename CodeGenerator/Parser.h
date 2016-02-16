#pragma once

#include <vector>
#include <string>

class Parser
{

public:
	Parser();
	~Parser();

	void Parse(std::vector<char> &input, std::vector<char> output);
	void generateBoilerPlate(); //generates the boilerplate code

private:
	std::vector<std::string> wordBuffer;
	std::vector<std::string> generatedCode;

	std::vector<std::string> includes;
	std::vector<std::string> namespaces;


    std::string generatePRINT(std::string strToPrint);
	int findIndex(std::vector<std::string> vec, std::string element);

	const std::string commandPrint = "PRINT";


};

