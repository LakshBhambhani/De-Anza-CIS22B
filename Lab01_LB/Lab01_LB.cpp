/* 
CIS22B 
Author:  Laksh Bhambhani
Lab 1: This program copies the content of input file to output file, destinations of which are inputted by the user
Pseudocode: 
Ask user for input file 
Ask user for output file
Open input file
Open output file
Read contents of input file
Cout to output file
Close files
Pause
Exit
*/ 

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fs;
	ofstream ft;
	string str;
	char sourcefile[50], destinationfile[50];

	cout << "Enter Source File with Extension: ";

	gets(sourcefile);

	fs.open(sourcefile);

	if (!fs)
	{
		cout << "Error in Opening Source File...!!!";
		exit(1);
	}

	cout << "Enter Destination File with Extension: ";

	gets(destinationfile);

	ft.open(destinationfile);

	if (!ft)
	{
		cout << "Error in Opening Destination File...!!!";
		fs.close();
		exit(2);
	}

	if (fs && ft)
	{
		while (getline(fs, str))
		{
			ft << str << "\n";
		}

		cout << "\n\n Source File Date Successfully Copied to Destination File...!!!";

	}
	else
	{
		cout << "File Cannot Open...!!!";
	}

	cout << "\n\n Open Destination File and Check!!!\n";

	fs.close();
	ft.close();

    cout << "Enter 0 to exit";

    int status;
    cin >> status;
    if(status == 0) return 0;
}