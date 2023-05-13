#include "Wishlist.h"
#include <iostream>
#include <vector>

Wishlist::Wishlist() //default constructor
{
    wishNum = 0;
    date = "00/00/0000";
    wishGenre = "Null";
    wishTitle = "Null";
    wishAuthor = "Null";
}

Wishlist::Wishlist(int user_wishNum, std::string user_date, std::string user_wishGenre, std::string user_wishTitle, std::string user_wishAuthor) //conversion constructor
{
    wishNum = user_wishNum;
    date = user_date;
    wishGenre = user_wishGenre;
    wishTitle = user_wishTitle;
    wishAuthor = user_wishAuthor;
}


std::string Wishlist::userWishlist(std::vector<Wishlist> &want) //allows user to wishlist items
{
    bool add{true};
    while(add)
    {
         std::cout << "What do you want to wishlist? (Num, Date, Genre, Title, Author)";
         int user_wishNum;
         std::string user_date;
         std::string user_wishGenre;
         std::string user_wishTitle;std::string user_wishAuthor;
         std::cin >> user_wishNum >> user_date >> user_wishGenre >> user_wishTitle >> user_wishAuthor;

         Wishlist userWish(user_wishNum, user_date, user_wishGenre, user_wishTitle, user_wishAuthor);
         want.push_back(userWish);
         std::cout << "Continue to add another book? 1 --> Yes| 0 --> No" << std::endl;
         std::cin >> add;
    }
}

int Wishlist::getWishNum() const
{
    return wishNum;
}

void Wishlist::setWishNum(int user_wishNum)
{
    wishNum = user_wishNum;
}

std::string Wishlist::getDate()
{
    return date;
}

void Wishlist::setDate(std::string user_date)
{
    date = user_date;
}

std::string Wishlist::getWishGenre()
{
    return wishGenre;
}

void Wishlist::setWishGenre(std::string user_wishGenre)
{
    wishGenre = user_wishGenre;
}

std::string Wishlist::getWishTitle()
{
    return wishTitle;
}

void Wishlist::setWishTitle(std::string user_wishTitle)
{
    wishTitle = user_wishTitle;
}

std::string Wishlist::getWishAuthor()
{
    return wishAuthor;
}

void Wishlist::setWishAuthor(std::string user_wishAuthor)
{
    wishAuthor = user_wishAuthor;
}