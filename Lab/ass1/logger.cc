#include "logger.hpp"

Logger::Logger(){
    logfile.open("logfile.txt",std::ios::out);
    std::cout << "Initializing Logger\n";
}

Logger& Logger::getInstance(){
    if (!logger){
        logger = new Logger;
        return *logger;
    }
    return *logger;
}

void Logger::flush(){
    logfile.flush();
}

void Logger::close(){
    this->flush();
    logfile.close();
}

void Logger::write(const std::string &x){
    logfile << x;
}

void Logger::writeLine(const std::string &x){
    logfile << x<<"\n";
}

void Logger::writeLine(const std::vector<std::string>&x){
    for(std::string a:x){
        logfile << a <<"\n";
    }
}

Logger* Logger::logger = 0;