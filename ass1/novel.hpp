#include "book.hpp"
#include "logger.hpp"
#include <vector>
#include <string>
typedef std::vector<std::string> Paragraph;
#ifndef _CHAPTER_H
#define _CHAPTER_H

class Chapter{
    public:
    int cno;
    std::string cName;
    std::vector<Paragraph> paragraphs;
};

#endif

#ifndef _NOVEL_H
#define _NOVEL_H

class Novel : public Book
{   std::vector<Chapter> chapters;
    public:
    void parseBook();
    void printBook(){};
    void query(const std::string&,int);

};
#endif
