#ifndef CYOACLASSHEADERS_WISHLIST_H
#define CYOACLASSHEADERS_WISHLIST_H

#include <string>
#include <vector>
class Wishlist
{
public:
    std::string userWishlist(std::vector<Wishlist> &want); //allows user to wishlist items

    Wishlist();

    Wishlist(int user_wishNum, std::string user_date, std::string user_wishGenre, std::string user_wishTitle, std::string wishAuthor);

    int getWishNum() const;

    void setWishNum(int wishNum);

    static std::string getDate();

    void setDate(std::string date);

    static std::string getWishGenre();

    void setWishGenre(std::string wishGenre);

    static std::string getWishTitle();

    void setWishTitle(std::string wishTitle);

    static std::string getWishAuthor();

    void setWishAuthor(std::string wishAuthor);

private:
    int wishNum{};
    static std::string date;
    static std::string wishGenre;
    static std::string wishTitle;
    static std::string wishAuthor;
};

#endif //CYOACLASSHEADERS_WISHLIST_H
