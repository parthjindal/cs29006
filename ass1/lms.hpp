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
    std::set<std::string> files;
    std::map<std::string,std::string>books;
    std::fstream indexFile;

public:
    LMS();
    void insertBook(Book &);
    void deleteBook(Book &);
    void updateSystem(const std::string &);
    std::vector<std::string> readDir(const std::string &);
};

Book* getObject(const std::string&);
#endif //LMS_H GUARD