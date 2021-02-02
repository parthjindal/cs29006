#include <iostream>
#include <string>
#include<regex>
#include<queue>
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
    Book& operator=(const Book&x);
    virtual ~Book(){};
    void setTitle(const std::string &);
    void setAuthor(const std::string &);
    void setPath(const std::string &);
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getPath() const;
    void parseHeader();
    virtual void parseBook(){};
    virtual void printBook(){};
    virtual void query(const std::string&,int){};
};
#endif // _BOOK_H