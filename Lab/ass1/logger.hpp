#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#ifndef _LOGGER_H
#define _LOGGER_H
class Logger{
    static Logger *logger;
    std::ofstream logfile;
    Logger();

public:
    static Logger &getInstance();
    void write(const std::string &x);
    void writeLine(const std::string &x);
    void writeLine(const std::vector<std::string> &x);
    void flush();
    void close();
    
    ~Logger(){
        if (logfile.is_open()){
            close();
        }
        std::cout << "Logger Destroyed";
    }
};
#endif