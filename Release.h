#ifndef CYOACLASSHEADERS_RELEASE_H
#define CYOACLASSHEADERS_RELEASE_H

#include <string>
class Release
{
public:
    void Upcoming(std::string releaseDate, std::string releaseAuthor, std::string publisher); //allows user to see release dates of books they entered

    Release(); //default constructor

    Release(std::string user_releaseDate, std::string user_releaseAuthor, std::string user_publisher); //conversion constructor

    std::string getReleaseDate();

    void setReleaseDate(std::string user_releaseDate);

    std::string getReleaseAuthor();

    void setReleaseAuthor(std::string user_releaseAuthor);

    std::string getPublisher();

    void setPublisher(std::string user_publisher);

private:
    static std::string releaseDate;
    static std::string releaseAuthor;
    static std::string publisher;
};
#endif //CYOACLASSHEADERS_RELEASE_H
