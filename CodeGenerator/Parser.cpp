#include "stdafx.h"
#include "Parser.h"


Parser::Parser()
{
}


Parser::~Parser()
{
}

int Parser::findIndex(std::vector<std::string> vec, std::string element)
{
	auto it = std::find(vec.begin(), vec.end(), element);
	return std::distance(vec.begin(),it);
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
	if (!input.empty())
		includes.push_back("\"stdafx.h\"");

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


	unsigned int iter = 0;
	for (std::string word : wordBuffer)
	{
		if (word == commandPrint)
		{
			generatedCode.push_back(generatePRINT(wordBuffer[iter++]));
			includes.push_back("<iostream>");
		}


		iter++;
	}
}
