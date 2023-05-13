#include "Release.h"
#include <iostream>
#include <vector>

Release::Release() //default constructor
{
    releaseDate = "00/00/0000";
    releaseAuthor = "Null";
    publisher = "Null";
}

Release::Release(std::string user_releaseDate, std::string user_releaseAuthor, std::string user_publisher) //conversion constructor
{
    releaseDate = user_releaseDate;
    releaseAuthor = user_releaseAuthor;
    publisher = user_publisher;
}

std::vector<Release> horizon;
void Release::Upcoming(std::string user_releaseDate, std::string user_releaseAuthor, std::string user_publisher) //allows user to see release dates of books they entered
{
    std::cout << "What do you want to add to upcoming releases? (Date, Author, Publisher): ";
    std::cin >> user_releaseDate >> user_releaseAuthor >> user_publisher;

    Release addRelease(user_releaseDate, user_releaseAuthor, user_publisher);
    horizon.push_back(addRelease);
}

std::string Release::getReleaseDate()
{
    return releaseDate;
}

void Release::setReleaseDate(std::string user_releaseDate)
{
    releaseDate = user_releaseDate;
}

std::string Release::getReleaseAuthor()
{
    return releaseAuthor;
}

void Release::setReleaseAuthor(std::string user_releaseAuthor)
{
    releaseAuthor = user_releaseAuthor;
}

std::string Release::getPublisher()
{
    return publisher;
}

void Release::setPublisher(std::string user_publisher)
{
    publisher = user_publisher;
}
