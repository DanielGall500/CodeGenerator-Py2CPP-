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
	{
		includes.push_back("\"stdafx.h\"");
		namespaces.push_back("std");
	}

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

	generatedCode.push_back("}"); //must be final line in generated code
}

void Parser::generateBoilerPlate()
{
	int linesUsed = 0;

	//handle includes
	for (unsigned int i = 0; i <= includes.size(); i++)
	{
		std::string incStatement = "#include " + includes[i] + ";";
		generatedCode.insert(generatedCode.begin() += i, incStatement);

		if (i == includes.size())
			addLine(i + 1);

		linesUsed = i;
	}

	//handle namespaces
	for (unsigned int i = 1; i <= namespaces.size(); i++)
	{
		std::string namespc = "using namespace " + namespaces[i] + ";";
		generatedCode.insert(generatedCode.begin() += (linesUsed + i), namespc);

		if (i == namespaces.size())
		{
			linesUsed += i + 1;
			addLine(linesUsed);
		}
	}

	//handle main function
	main = "int main()";

	linesUsed++;
	generatedCode.insert(generatedCode.begin() += linesUsed, main);
	linesUsed++;
	generatedCode.insert(generatedCode.begin() += linesUsed, "{");
}

void Parser::addLine(int numWhere)
{
	generatedCode.insert(generatedCode.begin() += numWhere, "/whitespace/");
}
