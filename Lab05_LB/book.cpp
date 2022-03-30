/*
CIS22B
Author:  Laksh Bhambhani
Lab 5: Main class for book
*/

#include <iostream>
#include <fstream>
using namespace std;
#include "book.h"

Book::Book(string isbn, string title, string author, string publisher, string dateAdded, int quantity, double wholesaleCost, double retailPrice)
{
	this->isbn = isbn;
	this->title = title;
	this->author = author;
	this->publisher = publisher;
	this->dateAdded = dateAdded;
	this->quantity = quantity;
	this->wholesaleCost = wholesaleCost;
	this->retailPrice = retailPrice;
}

Book::Book(Book &book){
	Book(book.getISBN(), book.getTitle(), book.getAuthor(), book.getPublisher(), book.getDateAdded(), book.getQuantity(), book.getWholesaleCost(), getRetailPrice());
}

Book::Book(){
	Book("0000", "default", "Tom Hanks", "NY Times", "01/01/2001", 100, 24.04, 30);
}

Book::~Book(){
	
}
