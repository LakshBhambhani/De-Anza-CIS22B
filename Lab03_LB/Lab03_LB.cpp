/*
CIS22B
Author:  Laksh Bhambhani
Lab 2: This program asks for a word, sorts the characters, and outputs the index of the character you're looking for
Ask user for input file
Open input file
Read contents of input file to array
selection sort it
get into loop of asking user for input for which word they would like to boolean search
boolean search, return and continue based on continue status
Pause
Exit
*/

#include <iostream>
#include <fstream>
using namespace std;

std::string whitespace = " \n\r\t\f\v";

void selectionSort(string array[], int ARRAY_SIZE)
{
	int min_index;
	string min_value;

	for (int start_index = 0; start_index < (ARRAY_SIZE - 1); start_index++)
	{
		min_index = start_index;
		min_value = array[start_index];

		for (int index = start_index + 1; index < ARRAY_SIZE; index++)
		{
			if (array[index] < min_value)
			{
				min_value = array[index];
				min_index = index;
			}
		}
		swap(array[min_index], array[start_index]);
	}
}

void swap(string &a, string &b)
{
	string temp = a;
	a = b;
	b = temp;
}

int binarySearch(string arr[], string x, int n)
{
	int lower = 0;
	int upper = n - 1;
	while (lower <= upper)
	{
		int mid = lower + (upper - lower) / 2;
		int res;
		if (x == (arr[mid]))
			res = 0;
		if (res == 0)
			return mid;
		if (x > (arr[mid]))
			lower = mid + 1;
		else
			upper = mid - 1;
	}
	return -1;
}

int main()
{
	ifstream fs;
	ofstream ft;
	string str;
	char sourcefile[50];
	int READSIZE = 1024;

	cout << "Enter Source File with Extension: ";

	gets(sourcefile);

	fs.open(sourcefile);

	if (!fs)
	{
		cout << "Error in Opening Source File...!!!";
		exit(1);
	}

	if (fs)
	{
		string myArray[1024];
		int actualWords = 0;

		for (int i = 0; i < READSIZE; ++i)
		{
			fs >> myArray[i];
			if (fs == 0)
			{
				// cout << fs;
			}
			else
			{
				// cout << fs << " " << myArray[i] << " " << i << endl;
				actualWords++;
			}
		}

		// int size = sizeof(myArray);
		// cout << size;
		selectionSort(myArray, 5);

		// size = sizeof(myArray);
		// cout << size;

		bool cont = true;

		while (cont)
		{
			string search;
			cout << "Enter the string you're finding: ";
			cin >> search;
			cout << "Looking for word: " << search << endl;
			int result = binarySearch(myArray, search, actualWords);
			if (result == -1)
				cout << ("Element not present") << endl;
			else
				cout << ("Element found at index ") << result << endl;
			if(search == "-1"){
				cont = false;
			}
		}
		cout << "Enter 0 to exit";

		int status;
		cin >> status;
		if (status == 0)
			return 0;
	}
	else
	{
		cout << "File Cannot Open...!!!";
	}

	// cout << binarySearch(letters, 0, 4, 'c');
}