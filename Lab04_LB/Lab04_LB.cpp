/*
CIS22B
Author:  Laksh Bhambhani
Lab 4: This program asks the user for a string and value to obfuscate the string by. In this way, it can encrypt and decrypt
the given string
Ask user for string
Ask user for value
Encode and save value
Decode and save value
Compare by printing it out
Pause
Exit
*/

#include <iostream>
#include <fstream>
using namespace std;

char *encrypt(char *input, int secret)
{
	string eString = "";
	for (int i = strlen(input)-1; i >= 0; i--)
	{
		int temp = (input[i] + secret);
		eString += (char)temp;
	}
	char *encryptedString = new char[eString.size()];
	strcpy(encryptedString, eString.c_str());
	return encryptedString;
}

char *decrypt(char *input, int secret)
{
	string dString = "";
	for (int i = strlen(input)-1; i >= 0; i--)
	{
		int temp = (input[i] - secret);
		dString += (char)temp;
	}
	char *decryptedString = new char[dString.size()];
	strcpy(decryptedString, dString.c_str());
	return decryptedString;
}

int main()
{
	string inputString;
	int secretKey;
	cout << "Please enter a positive whole number for the secret key: ";
	cin >> secretKey;
	cout << "Please enter a multi-line input. Type \"end\" followed by the Enter key to end providing input\n";
	string line;

	while (getline(cin, line))
	{
		if (line == "end")
			break;
		if (!line.empty() && line != " ")
		{
			if (!inputString.empty())
				inputString += "\n";
			inputString += line;
		}
	}

	char *cstr = new char[inputString.size() + 2];
	strcpy(cstr, inputString.c_str());
	cout << "Your original text is:\n"
		 << cstr << endl;
	char *encryptedString = encrypt(cstr, secretKey);

	cout << "Your encrypted text is:\n"
		 << encryptedString << endl;

	char *decryptedString = decrypt(encryptedString, secretKey);

	cout << "Your decrypted text is:\n"
		 << decryptedString << endl;

	cout << "Enter 0 to exit";

	int status;
	cin >> status;
	if (status == 0)
		return 0;
}