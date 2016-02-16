//********************************************************************
// Course: CPSC2620 Fall 2013
// Name: Josh Tymburski
// Assignment #4
// Question #2
// Professor: Howard Cheng
// Program: LineEditor.cc
// Purpose: Program takes all words from a file, and finds the key, IE,
//          the letters of the word organized alphabetically, of each
//          word. It stores each that correlates with a key into a
//          vector under that key. It then prints out each key, and all
//          the anagrams found in the file that correlates to that key.
// Programming Partner: Anthony Tymburski
// Software Used: Geany
//********************************************************************
#include<iostream>
#include<map>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

// Function Prototypes
string signature(const string& w);

int main()
{
	// Variable Declarations
	ifstream anagramFile;
	string word,key,fileName;
	map<string, vector<string>> anagramMap;
	map<string, vector<string>>::iterator it;
		
	cout << "Please enter the name of the file being entered into the "
		 << "system: ";
	cin >> fileName;
	
	anagramFile.open(fileName.c_str());
	
	// Loop through ensuring that the end of file hasn't been reached
	while (!anagramFile.eof())
	{
		anagramFile >> word;
		
		// Find the key of the word
		key = signature(word);
		
		// Implement the word into the correct key
		anagramMap[key].push_back(word);
	}
	
	// Set the iterator to the beginning
	it = anagramMap.begin();
	
	cout << endl;
	cout << "The list is formatted as follows. It starts with the key"
		 << endl << "and prints out all associated anagrams found"
		 << " from the file with that key." << endl << endl;
	
	// Loop through until the end of the map	 
	while (it != anagramMap.end())
	{
		cout << "Key: " << it->first << " Anagrams: ";
		
		// Print out each element in each key
		for (vector<string>::iterator it2 = it->second.begin(); 
			 it2 != it->second.end()-1; ++it2)
			cout << *it2 << " ";
			
		cout << endl;
		++it;
	}
		
	return 0;
}
//********************************************************************
// Function finds the alphabetically sorted key of the given string w
//********************************************************************
string signature(const string& w)
{
	string sortedString = w;
	sort(sortedString.begin(), sortedString.end());
	
	return sortedString;
}
