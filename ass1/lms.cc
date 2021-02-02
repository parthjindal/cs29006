#include "lms.hpp"

//Init LMS (Read Index.txt and Store bookname and typess)
LMS::LMS(const string&x):pathDir(x){}

void LMS::readIndex(){
    using namespace std;
    ifstream indexFile;
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


void LMS::listBook(){
    using namespace std;
    for(Book* x:books){
        x->parseHeader();
        cout << "*****************\n";
        cout << "Book: " << x->getTitle() << "\n";
        cout << "Author: " << x->getAuthor() << "\n";
        cout << "Path: " << x->getPath() << "\n\n";
    }
    return ;
}


std::vector<Book*> LMS::getBooks(std::string& key,std::string &keytype){
    using namespace std;
    transform(key.begin(), key.end(), key.begin(), ::tolower);
    vector<Book*> y;

    if(keytype == "name"){
        for(Book* x:books){
            string name(x->getTitle());
            transform(name.begin(),name.end(),name.begin(),::tolower);
            if(name.find(key) != string::npos)
                y.push_back(x);
        }
    }
    else
    if(keytype == "author"){
        for(Book* x:books){
            string name(x->getAuthor());
            transform(name.begin(),name.end(),name.begin(),::tolower);
            if(name.find(key) != string::npos)
                y.push_back(x);
        }
    }
    return y;
}

void LMS::deleteBook(Book* y){
    std::vector<Book*>::reverse_iterator itr;

    for(itr = books.rbegin();itr < books.rend();++itr){
        if(*(*itr) == *y){
            Book* temp = *(itr);
            books.erase((itr+1).base());
            delete temp;
            break;
        }
    }
}

void LMS::freeBook(Book* t){
    std::vector<Book*>::iterator itr;
    for(itr = books.begin();itr < books.end();itr++){
        if(*(*itr) == *t){
            Book* temp = *itr;
            *itr = t;
            delete temp;
            break;
        }
    } 
}

void LMS::updateSystem(){
    using namespace std;
    vector<string> files = readDir(pathDir); //files in dir

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
    std::vector<Book*>::reverse_iterator itr;

    for(itr = books.rbegin();itr < books.rend();++itr){
        (*itr)->parseHeader();
        if(bookpairs.find((*itr)->getTitle()) == bookpairs.end()){
            cout << "here";
            Book* temp = *(itr);
            books.erase((itr+1).base());
            delete temp;
        }
    }
    writeToIndex();
}

std::string LMS::getBookType(const string&x){
    return bookpairs.find(x)->second;
}


void LMS::writeToIndex(){
    using namespace std;
    map<string, string>::iterator m_itr;
    ofstream indexFile;
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
    else
    if( x == "Play"){
        Book* book = new Play;
        return book;
    }
    return new Book;
}