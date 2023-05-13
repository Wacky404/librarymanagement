#ifndef CYOACLASSHEADERS_LIBRARY_H
#define CYOACLASSHEADERS_LIBRARY_H

#include<string>
#include<vector>
class Library
{
public:

    void account_creation(std::string name); //lets user create an account

    static void addBook(std::vector<Library> &shelves);

    void bookSort(std::string book_title);  //sorting books that saved in vector

    Library(); //default constructor

    Library(int user_seriesNum, std::string user_genre, std::string user_book_title, std::string user_author); //conversion constructor

    int getSeriesNum() const;

    void setSeriesNum(int user_seriesNum);

    static std::string getGenre();

    void setGenre(std::string user_genre);

    static std::string getBookTitle();

    void setBookTitle(std::string user_book_title);

    static std::string getAuthor();

    void setAuthor(std::string user_author);

private:
    int seriesNum{};
    static std::string genre;
    static std::string book_title;
    static std::string author;
};

#endif //CYOACLASSHEADERS_LIBRARY_H
