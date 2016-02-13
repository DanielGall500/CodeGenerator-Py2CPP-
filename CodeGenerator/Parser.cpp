#include "stdafx.h"
#include "Parser.h"


Parser::Parser()
{
}


Parser::~Parser()
{
}

/*
Commands:
CREATE
COLLECT
PRINT
*/

std::string Parser::generatePRINT(std::string strToPrint)
{
	return "std::cout << \"" + strToPrint + "\" << std::endl;";
}

void Parser::Parse(std::vector<char> &input, std::vector<char> output)
{
	std::string builtWord;
	for (char &c : input)
	{
		if (c != ' ')
			builtWord += c;
		else
		{
			wordBuffer.push_back(builtWord);
			builtWord = "";
		}
    }

	for (std::string word : wordBuffer)
	{
		if (word == commandPrint)
			generatePRINT(wordBuffer[std::distance(wordBuffer.begin(), word.]);
	}
}
