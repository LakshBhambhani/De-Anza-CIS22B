/*
CIS22B
Author:  Laksh Bhambhani
Lab 5:
Takes in a file to read books from
Prints out info for each book
Pause
Exit
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include "book.cpp"

using namespace std;

int main()
{
    ifstream input("bookdata.txt");
    int bookNumber = 0;

    Book books[10];

    for (std::string info; getline(input, info);)
    {
        string splitInfo[8];
        int i = 0;
        stringstream ssin(info);
        while (ssin.good() && i < 8)
        {
            ssin >> splitInfo[i];
            ++i;
        }
        Book book(splitInfo[0], splitInfo[1], splitInfo[2], splitInfo[3], splitInfo[4], stoi(splitInfo[5]), stod(splitInfo[6]), stod(splitInfo[7]));
        books[bookNumber] = book;
        bookNumber++;
    }

    for (int i = 0; i < bookNumber; i++)
    {
        cout << "Book #" << (i+1) << ": " << books[i].getISBN() << " " << books[i].getTitle() << " " << books[i].getAuthor() << " " << books[i].getPublisher() << " " << books[i].getDateAdded() << " " << books[i].getQuantity() << " " << books[i].getWholesaleCost() << " " << books[i].getRetailPrice() << endl;
    }

    cout << "Enter 0 to exit";

	int status;
	cin >> status;
	if (status == 0)
		return 0;
}