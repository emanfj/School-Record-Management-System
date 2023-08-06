#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void read_record(string fileName)
{
	//file pointer
	fstream fin;

	//open an existing file
	fin.open(fileName, ios::in);

	//read data as string vector
	vector<string> row;
	string line, word, temp;

	while (fin >> temp) {

		row.clear();

		
		getline(fin, line);

		// used for breaking words
		stringstream ss(line);

		// read every column data of a row and
		// store it in a string variable, 'word'
		while (getline(ss, word, ', ')) {

			// add all the column data
			// of a row to a vector
			row.push_back(word);
		}
		}
	}
}
