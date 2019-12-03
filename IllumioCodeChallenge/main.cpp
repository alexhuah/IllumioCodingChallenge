#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "NAT.h";

using namespace std;

//Function to return a class object with the ip and port
NAT getIpPortPair(string* line, int* end)
{
	int beginning = 0;
	*end = (*line).find(":");
	string ip = (*line).substr(beginning, *end);
	beginning = *end + 1;
	*end = (*line).find(",");
	string port = (*line).substr(beginning, *end - beginning);
	return NAT(ip, port);
}

//Function to open NAT.txt file and populate the table
void openNATFile(char* fileName, map<NAT, string>* table)
{
	string line;
	ifstream inputFile(fileName);
	if (inputFile.is_open())
	{
		while (getline(inputFile, line))
		{
			int end = 0;
			NAT n1 = getIpPortPair(&line, &end);
			string value = line.substr(end + 1, line.length() - end);
			table->insert(pair<NAT, string>(n1, value));
		}
	}
	inputFile.close();
}

//Function to open FLOW.txt file and begin translating ip NAT's.
void openFLOWFile(char* fileName, map<NAT, string>* table)
{
	string line;
	ifstream flowFile(fileName);
	ofstream outputFile("OUTPUT.txt");
	if (flowFile.is_open())
	{
		while (getline(flowFile, line))
		{
			int end = 0;
			NAT n1 = getIpPortPair(&line, &end);
			auto it = table->find(n1);
			if (it != table->end())
			{
				outputFile << line << " -> " << it->second << endl;
			}
			else
			{
				outputFile << "No nat match for " << line << endl;
			}
		}
	}
	flowFile.close();
	outputFile.close();
}

int main(int argc, char* argv[])
{
	map<NAT, string> table;

	openNATFile(argv[1], &table);
	openFLOWFile(argv[2], &table);

	return 0;
}