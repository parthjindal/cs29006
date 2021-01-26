#include "lms.hpp"

LMS::LMS(){
    using namespace std;
    indexFile.open("index.txt", ios::out | ios::in);
    if (indexFile.is_open()){
        string line;
        while (getline(indexFile, line)){
            std::string b("{"),e("}");
            // cout << line.find(b) +1 ;
            string Name(line.substr(line.find(b)+1,line.find(",") -1-line.find(b)));
            // cout << Name;
            string bookType(line.substr(line.find(",")+1,line.find(e)-1 -line.find(",")));
            // cout << bookType;
            books.insert(pair<string,string>(Name,bookType));
        }
    }
}


static bool endsWith(const std::string& str, const std::string& suffix)
{
    return str.size() >= suffix.size() && 0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
}


std::vector<std::string> LMS::readDir(const std::string &path){
    DIR *dir;
    struct dirent *ent;
    std::vector<std::string> newFiles;
    Logger &logger = Logger::getInstance();
    if ((dir = opendir(path.c_str())) != NULL){
        while ((ent = readdir(dir)) != NULL){
            std::string fileName(ent->d_name);
            if(!endsWith(fileName,".txt"))
                continue;
            newFiles.push_back(path+"/"+fileName);
        }
    }
    closedir(dir);
    return newFiles;
}

void LMS::updateSystem(const std::string &path){
    using namespace std;
    vector<string> dirFiles = readDir(path);
    vector<string>::iterator itr;
    string bookType;
    Logger& logger = Logger::getInstance();
    map<string,string> updatedBooks;
    for (itr = dirFiles.begin(); 
         itr != dirFiles.end(); ++itr) 
    {   Book* book = new Book;
        book->parseHeader(*itr);
        if(this->books.find(book->getTitle()) == this->books.end()){
            cout << "Enter Book: " <<book->getTitle() << "'s Type"<<endl;
            cin >> bookType;
            updatedBooks.insert(pair<string,string>(book->getTitle(),bookType));
        }else{
            bookType = books.find(book->getTitle())->second;
            updatedBooks.insert(pair<string,string>(book->getTitle(),bookType));
        }
        delete book;
    }
    
}

Book* getObject(const std::string&x){
    if(x == "Novel"){
        Book* book = new Novel;
        return book;
    }
    return new Book;
}