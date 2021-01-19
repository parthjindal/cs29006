#include<iostream>
#include<string>

#ifndef _BOOK_H
#define _BOOK_H

class Book{
    std::string title;
    std::string author;
    public :
    Book();
    Book(const std::string&a,const std::string &b);
    int a;
    void setTitle(const std::string &name);
    void setAuthor(const std::string &name);
    std::string getTitle();
    std::string getAuthor();
    void parseHeader(const std::string &fileName);
    virtual void parseBook(const std::string &fileName) = 0;
    virtual void printBook() = 0;
    virtual void query() = 0;
};
#endif