#include "book.hpp"
#include "logger.hpp"
#include <vector>
#include <string>
typedef std::vector<std::string> para;
#ifndef _CHAPTER_H
#define _CHAPTER_H

class Chapter{
    std::string chapterName;
    std::vector<para> paragraphs;
};

#endif

#ifndef _NOVEL_H
#define _NOVEL_H

class Novel : public Book
{   
    public:
    void parseBook(const std::string &fileName){};
    void printBook(){};
    void query();

};
#endif
