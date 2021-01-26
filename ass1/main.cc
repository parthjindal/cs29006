#include<iostream>
#include"book.hpp"
#include"logger.hpp"
#include"novel.hpp"
#include"lms.hpp"

using namespace std;

int main(){
    // Novel x;
    // Book&a = x;
    // vector<Book> books;
    // books.push_back(x);
    // a.parseHeader("moby-dick.txt");
    // a.query();
    // cout << a.getTitle();
    LMS lms;
    // lms.readDir("/home/parth/cs29006/files");
    lms.updateSystem("/home/parth/cs29006/files");
    Logger& logger = Logger::getInstance();
    logger.close();

}