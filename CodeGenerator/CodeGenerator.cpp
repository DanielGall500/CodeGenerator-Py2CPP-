// CodeGenerator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string inputDir = "C:/Users/dano/Desktop/CodeGenerator/input.txt";
	string outputDir = "C:/Users/dano/Desktop/CodeGenerator/output.txt";

	ifstream input;
	ofstream output;

	vector<char> byteVector(0);

	string line;
	
	input.open(inputDir, ios::in);

	if (input.is_open())
	{
        while (getline(input, line))
		{
            for (char &c : line)
			{
				byteVector.push_back(c);
				cout << "Pushed Back: " << c << endl;
			}
		}

		input.close();
	}
	else
		cout << "Error: File Wont Open";

	for (char &c : byteVector)
	{
		cout << c;
	}



	cin.get();

}

