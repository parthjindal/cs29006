#include "lms.hpp"

//Init LMS (Read Index.txt and Store bookname and typess)
LMS::LMS(){
    using namespace std;
    indexFile.open("index.txt", ios::in);
    if (indexFile.is_open()){
        string line;
        while (getline(indexFile, line)){
            string b("{"), e("}");
            string Name(line.substr(line.find(b) + 1, line.find(":") - 1 - line.find(b)));
            string bookType(line.substr(line.find(":") + 1, line.find(e) - 1 - line.find(":")));
            bookpairs.insert(pair<string, string>(Name, bookType));
        }
    }
    indexFile.close();
}

static bool endsWith(const std::string &str, const std::string &suffix){
    return str.size() >= suffix.size() && 
        0 == str.compare(str.size() - suffix.size(), suffix.size(), suffix);
}

//returns all files ending with.txt in said directory
std::vector<std::string> LMS::readDir(const std::string &path){
    using namespace std;
    DIR *dir;
    struct dirent *ent;
    vector<string> files;

    if ((dir = opendir(path.c_str())) != NULL){
        while ((ent = readdir(dir)) != NULL){
            string fileName(ent->d_name);
            if (!endsWith(fileName, ".txt"))
                continue;
            files.push_back(path + "/" + fileName);
        }
    }
    closedir(dir);
    return files;
}


void LMS::updateSystem(const std::string &path){
    using namespace std;
    vector<string> files = readDir(path); //files in dir

    string bookType;
    map<string, string> updatedBooks;

    for (string file:files){
        Book *book = new Book;
        book->setPath(file);
        book->parseHeader();

        if (bookpairs.find(book->getTitle()) == bookpairs.end()){
            cout << "Enter Book: " << book->getTitle() << "'s Type" << endl;
            cin >> bookType;
            updatedBooks.insert(pair<string, string>(book->getTitle(), bookType));
            Book* newBook = getObject(bookType);
            newBook->setPath(file);
            books.push_back(newBook);
        }
        else{
            bookType = bookpairs.find(book->getTitle())->second;
            updatedBooks.insert(pair<string, string>(book->getTitle(), bookType));
        }
        delete book;
    }
    bookpairs.clear();
    bookpairs = updatedBooks;

    map<string, string>::iterator m_itr;
    indexFile.open("index.txt", ios::out);
    if (indexFile.is_open()){
        for (m_itr = bookpairs.begin();
             m_itr != bookpairs.end(); ++m_itr){
            indexFile << "{" << m_itr->first << ":" << m_itr->second << "}\n";
        }
    }
    indexFile.close();
}

Book* getObject(const std::string &x){
    if (x == "Novel"){
        Book *book = new Novel;
        return book;
    }
    return new Book;
}