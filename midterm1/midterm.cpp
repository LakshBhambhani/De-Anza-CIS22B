/*
CIS22B
Author:  Laksh Bhambhani
Midterm 1: This program copies the content of input file to output file, changing a couple things along the way
Ask user for number between 1 and 9
Open input file
Open output file
Read contents of input file
modify content
Cout to output file
Close files
Pause
Exit
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// function to perform the task
// accepts the parameter str as the text to
// be stored in text file
void reverse(int num)
{
	char ch;

	// storing the position of  end of the file
	int pos = 0;

	// object for reading the contents of the
	// first text file
	ifstream ifs;
	ifs.open("input.txt", ios::in);

	// object for writing in to the text file 2
	ofstream ofs;
	ofs.open("output.txt", ios::out);

	while (ifs.get(ch))
	{
		pos++;
	}

	ifs.close();
	ifs.open("input.txt", ios::in);

	// putting the read pointer to the last alphabet
	// of the file
	ifs.seekg(--pos);
	// ifs.get(ch)
	// cout << ch << endl;

	while (pos >= 0)
	{
		// reading from the file 1
		ifs.get(ch);
		// writing to the file 2
		if (isdigit(ch))
		{
			int number = (((int)ch-48)+num);
			char s = '0'+number; 
			if(number <= 9){
				ofs.put(s);
			}
			else{
				number -=10;
				s = '0'+number; 
				ofs.put(s);
			}
		}
		else
		{
			if (islower(ch))
			{
				ofs.put(toupper(ch));
			}
			else
			{
				ofs.put(tolower(ch));
			}
		}

		/* shifting read pointer position one
		alphabet backwards in the text file */
		pos--;

		ifs.seekg(pos);
	}

	ifs.close();
	ofs.close();
}

// Driver code
int main()
{
	int number;
	// sample input 1
	cout << "Enter a number between 1 and 9: ";
	cin >> number;

	reverse(number);

	cout << "Enter 0 to exit";

	int status;
	cin >> status;
	if (status == 0)
		return 0;
}
