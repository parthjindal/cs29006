#include "book.hpp"
#include "novel.hpp"
#include "play.hpp"
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <dirent.h>
#include <iterator>

#ifndef LMS_H
#define LMS_H

class LMS
{
    std::map<std::string, std::string> bookpairs;
    std::vector<Book *> books;
    std::string pathDir;

    void readIndex();
    void writeToIndex();

public:
    LMS(){};
    LMS(const string &x);
    void updateSystem();
    void listBook();
    void freeBook(Book* );
    std::string getBookType(const string&);
    void deleteBook(Book *);
    std::vector<Book *> getBooks(std::string &, std::string &);

    std::vector<std::string> readDir(const std::string &);
};

Book *getObject(const std::string &);
#endif //LMS_H GUARD