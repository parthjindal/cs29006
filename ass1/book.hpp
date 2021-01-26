#include<iostream>
#include<string>

#ifndef _BOOK_H
#define _BOOK_H

class Book{
    std::string title;
    std::string author;
    std::string path;
    public :
    Book();
    Book(const std::string&x,const std::string &y,const std::string&z);
    void setTitle(const std::string &name);
    void setAuthor(const std::string &name);
    void setPath(const std::string &name);
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getPath() const;
    void parseHeader(const std::string &fileName);
    virtual void parseBook(const std::string &fileName){};
    virtual void printBook(){};
    virtual void query(){};
};
#endif