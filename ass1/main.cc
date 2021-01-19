#include<iostream>
#include"book.hpp"
#include"logger.hpp"
#include"novel.hpp"

using namespace std;

int main(){
    Novel x;
    Book* a = &x;
    // a->parseHeader("moby-dick.txt");
    a->query();
    Logger& logger = Logger::getInstance();
    logger.write("Hello");
    logger.close();

}