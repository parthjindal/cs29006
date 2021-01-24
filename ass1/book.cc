#include"book.hpp"
#include"logger.hpp"
#include<iostream>
#include<fstream>

Logger& logger = Logger::getInstance();

Book::Book(){
    logger.writeLine("Book Initialized");
}

void Book::parseHeader(const std::string &fileName){
    std::ifstream file;
    file.open(fileName,std::ios::in);
    
    if(file.is_open()){

        std::string line;
        std::string header("*** START OF THIS PROJECT GUTENBERG EBOOK");
        std::string title("Title:");
        std::string author("Author:");

        while(std::getline(file,line)){
            if(line.find(title) == 0){
                this->title.insert(0,line.substr(line.find(" ")+1,line.size()-1));
                logger.writeLine("TITLE INITIALIZED");
            }
            else
            if(line.find(author) == 0){
                this->author.insert(0,line.substr(line.find(" ")+1,line.size()-1));
                logger.writeLine("AUTHOR INITIALIZED");
            }
            else
            if(line.find(header) == 0){
                logger.writeLine("END OF HEADER");
                break;
            }
        }

    }
    
    file.close();


}

Book::Book(const std::string &a,const std::string &b):title(a),author(b){
}

std::string Book::getTitle(){
    return title;
}