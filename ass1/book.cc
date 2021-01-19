#include"book.hpp"
#include"logger.hpp"
#include<iostream>
#include<fstream>
#include<regex>

Logger& logger = Logger::getInstance();

Book::Book(){
    logger.writeLine("Book Initialized");
}

void Book::parseHeader(const std::string &fileName){
    std::ifstream file;
    file.open(fileName,std::ios::in);
    std::string text;
    getline(file,text);
    while(!std::regex_match(text,std::regex("*START OF THIS PROJECT GUTENBERG EBOOK*"))){
        std::cout << text;
        getline(file,text);
        //
        //  TODO:
        //  TODO:
        //  TODO: 
        //      
    }
    file.close();
}

Book::Book(const std::string &a,const std::string &b):title(a),author(b){
}