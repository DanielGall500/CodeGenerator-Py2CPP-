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
TODO:
CREATE
COLLECT
PRINT
*/

std::string Parser::generateCOUT(std::string strToPrint)
{
	return indentLvl1 + "cout << \"" + strToPrint + "\" << endl;";
}

void Parser::Parse(std::vector<char> &input)
{
	generateBoilerPlate();

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
		unsigned int preVal = iter - 1;
		unsigned int nextVal = iter + 1;

		if (word == commandPrint)
		{
			unsigned int printVal = iter + 1; //the next index in the vector

			generatedCode.push_back(generateCOUT(wordBuffer[printVal]));

			includes.push_back("<iostream>");
		}

		if (word == commandVar)
		{
			std::string generated = generateVARIABLE(wordBuffer[preVal], wordBuffer[nextVal]);
			std::cout << generated << std::endl;
			generatedCode.push_back(generated);
		}


		iter++;
	}

	//generatedCode.push_back("}"); //must be final line in generated code

}

void Parser::generateBoilerPlate()
{
	//int linesUsed = 0;

	////handle includes
	//for (unsigned int i = 0; i <= (includes.size() - 1); i++)
	//{
	//	std::string incStatement = "#include " + includes[i];

	//	if (std::find(generatedCode.begin(), generatedCode.end(), incStatement) == generatedCode.end())
	//		generatedCode.insert(generatedCode.begin() + i, incStatement);

	//	if (i == includes.size() - 1)
	//		addLine(i + 1);

	//	linesUsed = i;
	//}

	////handle namespaces
	//for (unsigned int i = 0; i <= (namespaces.size() - 1); i++)
	//{
	//	std::string namespc = "using namespace " + namespaces[i] + ";";
	//	generatedCode.insert(generatedCode.begin() += (linesUsed + i), namespc);

	//	if (i == namespaces.size() - 1)
	//	{
	//		linesUsed += i + 1;
	//		addLine(linesUsed);
	//	}
	//}

	////handle main function
	//main = "int main()";

	//
	//linesUsed++;
	//generatedCode.insert(generatedCode.begin() += linesUsed, main);
	//linesUsed++;
	//generatedCode.insert(generatedCode.begin() += linesUsed, "{");
	int mainfLines = 2, refactoringLines = 2;

	int totalLinesAllowed = includes.size() + namespaces.size() + mainfLines + refactoringLines;
	std::cout << "Total lines allowed: " + totalLinesAllowed << std::endl;

	for (unsigned int i = 0; i <= totalLinesAllowed; i++)
	{
		for (unsigned int j = 0; j <= (includes.size() - 1); j++)
		{
			std::string incStatement = "#include " + includes[j];


			if (std::find(includes.begin(), includes.end(), incStatement) == includes.end())
			{
				generatedCode[i] = incStatement;
				i++;
			}
			else 
			{
				generatedCode[i] = incStatement;
				includes.erase(includes.begin() + j);
			}

		}


	}

}

void Parser::addLine(int numWhere)
{
	generatedCode.insert(generatedCode.begin() += numWhere, "/whitespace/");
}

void Parser::stream(std::string directory)
{
	streamOut.open(directory, std::ios::out);

	if (streamOut.is_open())
	{
		for (std::string line : generatedCode)
		{
			if (line == "/whitespace/")
			{
				streamOut << "\n";
			}
			else
			{
				streamOut << line << std::endl;
			}
		}
		streamOut.close();
	}
	else
	{
		std::cout << "File Wont Open: " << directory << std::endl;
	}
}

void Parser::setPrintCommand(std::string command)
{
	commandPrint = command;
}

std::string Parser::getPrintCommand()
{
	return commandPrint;
}

std::string Parser::generateVARIABLE(std::string varName, std::string value)
{
	varType valueType;
	std::string type;

	if (isdigit(value[0]))
		valueType = INT;
    else if (value == "true" || value == "false")
		valueType = BOOL;
    else
		valueType = STRING;

	if (valueType == INT)
	{
		int convertedValue = int(&value);
		type = "int";
	}
	else if (valueType == BOOL)
	{
		bool convertedValue = bool(&value);
		type = "bool";
	}
	else //string
	{
		std::string convertedValue = value; 
		type = "string";
	}
	
	return indentLvl1 + type + " " + varName + " = " + value + ";";
}
