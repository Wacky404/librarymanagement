#include <iostream>
#include <fstream>
#include "Library.h"
#include "Wishlist.h"
#include "Release.h"
//Left off: Debugging, headers/cpp files, so that I can run the first grouping of quick code, in main.cpp, and debug it.
int main()
{
    std::vector<Library> shelves;
    std::vector<Wishlist> want;


    std::cout << "Welcome to BTY's Library Management. Let us be your Librarian!" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;

    std::ofstream myFile;
    std::string fileName = "library.txt";
    myFile.open(fileName);
    myFile.seekp(0, std::ios::end);
    if (myFile.tellp() == 0) {
        std::cout << "Lets set up your Library:" << std::endl;
        Library::addBook(shelves);
        for (int i = 0; i < shelves.size(); i++)
        {
            myFile << shelves[i].getSeriesNum() << ", " << shelves[i].getGenre() << ", " << shelves[i].getBookTitle() << ", " << shelves[i].getAuthor() << "\n";
        }
        std::cout << "Library created successfully! Thank you for choosing BTY's Library Management." << std::endl;
        myFile.close();
    }

    bool exitChoice{true};
    while(exitChoice)
    {
        std::cout << "What application do you want to run:\n" << "1 --> Library| " << "2 --> Wishlist| " << "3 --> Upcoming Releases" << std::endl;
        int appRun{};
        std::cin >> appRun;

        if (appRun == 1) {

            std::string currentBookTitle = " "; //moved out of while on scope might move?
            std::string currentAuthor = " ";
            std::string currentStart = " ";

            bool on{true};
            while (on) {
                std::cout << "(V)iew Library| (C)urrently Reading| (H)ave Read| (T)o Be Read\n";
                char userChoice;
                std::cin >> userChoice;

                std::string searchBookTitle;
                std::string line;
                std::ifstream readFile;
                std::ofstream doneFile;
                std::ifstream displayDoneFile;
                std::string fileNameDone = "AlreadyRead.txt";
                bool inputting{true};
                int update{};
                switch (userChoice) {
                    case 'V':
                        for (int i = 0; i < shelves.size(); i++)
                        {
                            myFile << shelves[i].getSeriesNum() << ", " << shelves[i].getGenre() << ", " << shelves[i].getBookTitle() << ", " << shelves[i].getAuthor() << "\n";
                        }
                        std::cout << "Exit the Library?: 0 --> Yes  1 --> No\n";
                        std::cin >> on;
                        break;
                    case 'C':
                        if(currentBookTitle == " ")
                        {
                            std::cout << "What is the title of the book you are currently reading: ";
                            std::getline(std::cin, currentBookTitle);
                            std::cout << "The author's name: ";
                            std::getline(std::cin, currentAuthor);
                            std::cout << "When did you start the book (MM/DD/YYYY): ";
                            std::getline(std::cin, currentStart);
                            std::cout << "Currently reading: " << currentBookTitle << ", by " << currentAuthor << ", Start Date: " << currentStart << "\n";
                        }
                        else
                        {
                            std::cout << "Currently reading: " << currentBookTitle << ", by " << currentAuthor << ", Start Date: " << currentStart << "\n";
                        }
                        std::cout << "Do you want to update currently reading? 1 --> Yes  2 --> No\n ";
                        std::cin >> update;
                        if(update == 1)
                        {
                            std::cout << "What is the title of the book you are currently reading: ";
                            std::getline(std::cin, currentBookTitle);
                            std::cout << "The author's name: ";
                            std::getline(std::cin, currentAuthor);
                            std::cout << "When did you start the book (MM/DD/YYYY): ";
                            std::getline(std::cin, currentStart);
                            std::cout << "Currently reading: " << currentBookTitle << ", by " << currentAuthor << ", Start Date: " << currentStart << "\n";
                        }
                        std::cout << "Exit the Library?: 0 --> Yes  1 --> No\n";
                        std::cin >> on;
                        break;
                    case 'H':
                        displayDoneFile.open(fileNameDone);
                        if (!displayDoneFile.is_open())
                        {
                            std::cout << "Error. " << fileNameDone << " cannot be opened.";
                            EXIT_FAILURE;
                        }
                        displayDoneFile.seekg(0, std::ios::end);
                        if (displayDoneFile.tellg() > 0)
                        {
                            while (std::getline(displayDoneFile, line))
                            {
                                std::cout << line << "\n";
                            }
                        }
                        displayDoneFile.close();
                        std::cout << "Do you want to add books to your already read? 0 --> Yes  1 --> No\n";
                        std::cin >> inputting;

                        doneFile.open(fileNameDone);
                        if (!doneFile.is_open())
                        {
                            std::cout << "Error. " << fileNameDone << " cannot be opened.";
                            EXIT_FAILURE;
                        }
                        while(inputting)
                        {
                            std::cout << "What books have you already read in your library (Book Title as you entered)? ";
                            std::getline(std::cin, line);
                            doneFile << line << "\n";
                            std::cout << "Add another book to read?: 0 --> Yes  1 --> No\n";
                            std::cin >> inputting;
                        }
                        doneFile.close();
                        std::cout << "Exit the Library?: 0 --> Yes  1 --> No\n";
                        std::cin >> on;
                        break;
                    case 'T':
                        std::cout << "Search for books in your Library (Book Title as you entered): ";
                        std::getline(std::cin, searchBookTitle);
                        readFile.open(fileName);
                        if(!myFile.is_open())
                        {
                            std::cout << "Unable to open file" << std::endl;
                            EXIT_FAILURE;
                        }
                        size_t pos;
                        while(getline(readFile, line))
                        {
                            pos = line.find(searchBookTitle);
                        }
                        if(pos != std::string::npos)
                        {
                            std::cout << searchBookTitle << " is in your Library.";
                        }
                        else
                        {
                            std::cout << searchBookTitle << " is not in your Library.";
                        }

                        std::cout << "Exit the Library?: 0 --> Yes  1 --> No\n";
                        std::cin >> on;
                        break;
                    default:
                        break;
                }
            }
        }
        if (appRun == 2) {
            bool on{true};
            while (on) {
                std::cout << "(V)iew Wishlist| (A)dd to Wishlist| (R)emove from Wishlist\n";
                char userChoice;
                std::cin >> userChoice;
                switch (userChoice) {
                    case 'V':
                        for (auto & element : want)
                        {
                            std::cout << Wishlist::getDate() << ", "
                                      << Wishlist::getWishGenre() << ", "
                                      << Wishlist::getWishTitle() << ", "
                                      << Wishlist::getWishAuthor() << "\n";
                        }
                        std::cout << "Exit the Wishlist?: 0 --> Yes  1 --> No\n";
                        std::cin >> on;
                        break;
                    case 'A':
                        std::cout << "Exit the Wishlist?: 0 --> Yes  1 --> No\n";
                        std::cin >> on;
                        break;
                    case 'R':
                        std::cout << "Exit the Wishlist?: 0 --> Yes  1 --> No\n";
                        std::cin >> on;
                        break;
                    default:
                        break;
                }
            }
        }
        if (appRun == 3) {
            bool on{true};
            while (on) {
                std::cout << "(V)iew Upcoming Releases| (A)dd to Upcoming Releases| (R)emove from Upcoming Releases\n";
                char userChoice;
                std::cin >> userChoice;
                switch (userChoice) {
                    case 'V':
                        std::cout << "Exit the Upcoming Releases?: 0 --> Yes  1 --> No\n";
                        std::cin >> on;
                        break;
                    case 'A':
                        std::cout << "Exit the Upcoming Releases?: 0 --> Yes  1 --> No\n";
                        std::cin >> on;
                        break;
                    case 'R':
                        std::cout << "Exit the Upcoming Releases?: 0 --> Yes  1 --> No\n";
                        std::cin >> on;
                        break;
                    default:
                        break;
                }
            }
        }
        std::cout <<"Exit BTY's Library Management?: 0 --> Yes  1 --> No\n";
        std::cin >> exitChoice;
    }
    std::cout << "© 2023 BTY's Library Management";
    return 0;
}
