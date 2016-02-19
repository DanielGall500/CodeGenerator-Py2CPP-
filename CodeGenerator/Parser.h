#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Parser
{

public:
	Parser();
	~Parser();

	void Parse(std::vector<char> &input);
	void stream(std::string directory);

	std::string getPrintCommand();
	void setPrintCommand(std::string command);

private:
	//Commands
	std::string commandPrint = "PRINT";


	std::string indentLvl1 = "    ";

    std::vector<std::string> wordBuffer;
	std::vector<std::string> generatedCode;

	std::vector<std::string> includes;
	std::vector<std::string> namespaces;

	std::string main;
    std::ofstream streamOut;

	std::string generatePRINT(std::string strToPrint);
	int findIndex(std::vector<std::string> vec, std::string element);
    void generateBoilerPlate();
	void addLine(int numWhere);

};

