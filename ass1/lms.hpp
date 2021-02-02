#include "book.hpp"
#include"novel.hpp"
#include <iostream>
#include <fstream>
#include <set>
#include<map>
#include <dirent.h>
#include"logger.hpp"
#include<iterator>

#ifndef LMS_H
#define LMS_H

class LMS{
    std::map<std::string,std::string>bookpairs;
    std::vector<Book*> books;
    std::fstream indexFile;
    void readIndex();
    void writeToIndex();
    public:
    LMS();
    void listBook();
    void deleteBook(Book*);
    std::vector<Book*> getBooks(std::string&,std::string&);
    void updateSystem(const std::string &);
    std::vector<std::string> readDir(const std::string &);
};

Book* getObject(const std::string&);
#endif //LMS_H GUARD