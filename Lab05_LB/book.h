/*
CIS22B
Author:  Laksh Bhambhani
Lab 5: Base class for book
*/

#include <iostream>
#include <fstream>
using namespace std;

class Book
{
    private:
        string isbn;
        string title;
        string author;
        string publisher;
        string dateAdded;
        int quantity;
        double wholesaleCost;
        double retailPrice;

    public:

        Book();
        Book(string, string, string, string, string, int, double, double);
        Book(Book &book);
        ~Book();

        string getISBN(){
            return isbn;
        }

        string getTitle(){
            return title;
        }
        
        string getAuthor(){
            return author;
        }

        string getPublisher(){
            return publisher;
        }

        string getDateAdded(){
            return dateAdded;
        }

        int getQuantity(){
            return quantity;
        }

        double getWholesaleCost(){
            return wholesaleCost;
        }

        double getRetailPrice(){
            return retailPrice;
        }

        void setISBN(string newIsbn){
            isbn = newIsbn;
        }

        void setTitle(string newTitle){
            title = newTitle;
        }
        
        void setAuthor(string newAuthor){
            author = newAuthor;
        }

        void setPublisher(string newPublisher){
            publisher = newPublisher;
        }

        void setDateAdded(string newDateAdded){
            dateAdded = newDateAdded;
        }

        void setQuantity(int newQuantity){
            quantity = newQuantity;
        }

        void setWholesaleCost(double newWholesaleCost){
            wholesaleCost = newWholesaleCost;
        }

        void setRetailPrice(double newRetailPrice){
            retailPrice = newRetailPrice;
        }
};