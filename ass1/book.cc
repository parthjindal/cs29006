#include "book.hpp"
#include "logger.hpp"
#include <iostream>
#include <fstream>

Book::Book() {}

Book::Book(const std::string &x,
           const std::string &y, const std::string &z) : title(x), author(y), path(z) {}

std::string Book::getTitle() const { return title; }
std::string Book::getAuthor() const { return author; }
std::string Book::getPath() const { return path; }

void Book::setTitle(const std::string &x) { title = x; }
void Book::setAuthor(const std::string &x) { author = x; }
void Book::setPath(const std::string &x) { path = x; }

Book::Book(const Book &x)
{
    title = x.title;
    author = x.author;
    path = x.path;
}

Book& Book::operator=(const Book &x){
    title = x.title;
    author = x.author;
    path = x.path;
    return *this;
}

void Book::parseHeader(){

    std::ifstream file;
    file.open(path, std::ios::in);

    if (file.is_open()){

        std::string line;
        std::string header("*** START OF THIS PROJECT GUTENBERG EBOOK");
        std::string title("Title:");
        std::string author("Author:");

        while (std::getline(file, line)){
            if (line.find(title) == 0)
                this->title = line.substr(line.find(" ") + 1);
            else if (line.find(author) == 0)
                this->author = line.substr(line.find(" ") + 1);
            else if (line.find(header) == 0)
                break;
        }
    }

    file.close();
}
