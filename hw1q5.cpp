#include <iostream>
#include <sstream>
#include <fstream>
#include <string> 

using namespace std;

void helper (stringstream &input, int len) 
{
	string word = ""; //empty string

	if (len == 0)
		return; // we are done

	char c;
	input >> c;

	while(!input.eof() && c != ' ' && c != '\n' && c != '\t')
	{
		word += c;
		input >> noskipws >> c;
	}

	helper(input, len -1);

	cout << word << endl;

}


int main (int argc, char* argv[])
{
	if(argc < 2) 
	{
		cout << "Your file name is not passed." << endl; 
		return 1;
	}

	ifstream file(argv[1]);

	if (file)
	{
		stringstream buffer;
		buffer << file.rdbuf(); // read contents from file

		string wordcount = "";
		char c;
		buffer >> c; 

		
		while(c != ' ' && c != '\n' && c != '\t')
		{
			
			wordcount += c;
			buffer >> noskipws >> c;
		
		}
		
		stringstream number(wordcount);

		int wordnumber;
		number >> wordnumber; // string 11 converted to integer 11 named wordnumber

		helper(buffer, wordnumber);

		file.close(); 
	}
	else
	{
		cout << "Unable to open input file: " << argv[1] << endl;
		return 1; 

	}

		return 0;
	
}