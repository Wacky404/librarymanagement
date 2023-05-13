#include "Library.h"
#include <iostream>
#include <algorithm>
#include <vector>

Library::Library()  //default constructor
{
    seriesNum = 1;
    genre = "Null";
    book_title = "Null";
    author = "Null";
}

Library::Library(int user_seriesNum, std::string user_genre, std::string user_book_title, std::string user_author) //conversion constructor
{
    seriesNum = user_seriesNum;
    genre = user_genre;
    book_title = user_book_title;
    author = user_author;
}

void account_creation(std::string name) //might delete !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "(Account Creation)" << std::endl;
    std::cout << "First name on account?:";
    std::getline(std::cin, name);
    std::cout << "Lets set up your account:" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    //here is where to input function for creation.
    std::cout << "Account created successfully! Thank you for choosing Cosmere Banking." << std::endl;
}

void Library::addBook(std::vector<Library> &shelves)   //adding books to the vector
{
    bool add{true};
    while(add) {
        std::cout << "(Shelves)" << std::endl;
        std::cout << "What is series number: ";
        int user_seriesNum{};
        std::cin >> user_seriesNum;

        std::cout << "What is genre: ";
        std::string user_genre;
        std::cin >> user_genre;

        std::cout << "What is book title: ";
        std::string user_book_title;
        std::cin >> user_book_title;

        std::cout << "What is author name: ";
        std::string user_author;
        std::cin >> user_author;

        Library userInput(user_seriesNum, user_genre, user_book_title, user_author);
        shelves.push_back(userInput);
        std::cout << "Continue to add another book? 1 --> Yes| 0 --> No" << std::endl;
        std::cin >> add;
    }
}

bool alphabetical(std::string a, std::string b) //might get rid of this; this is for booksort function
{
    return(a > b);
}

void Library::bookSort(std::string book_title)  //sorting books that saved in vector
{
   // std::sort(shelves.begin(), shelves.end(), alphabetical);
}

int Library::getSeriesNum() const
{
    return seriesNum;
}

void Library::setSeriesNum(int user_seriesNum)
{
    seriesNum = user_seriesNum;
}

std::string Library::getGenre()
{
    return genre;
}

void Library::setGenre(std::string user_genre)
{
    genre = user_genre;
}

std::string Library::getBookTitle()
{
    return book_title;
}

void Library::setBookTitle(std::string user_book_title)
{
    book_title = user_book_title;
}

std::string Library::getAuthor()
{
    return author;
}

void Library::setAuthor(std::string user_author)
{
    author = user_author;
}

