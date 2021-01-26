#include <iostream>
#include <string>

#ifndef _BOOK_H
#define _BOOK_H

class Book{
    std::string title;
    std::string author;
    std::string path;

public:
    Book();
    Book(const std::string &x, const std::string &y, const std::string &z);
    Book(const Book &x);
    void setTitle(const std::string &);
    void setAuthor(const std::string &);
    void setPath(const std::string &);
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getPath() const;
    void parseHeader(const std::string &);
    virtual void parseBook(const std::string &){};
    virtual void printBook(){};
    virtual void query(){};
};
#endif // _BOOK_H