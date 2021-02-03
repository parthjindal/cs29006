#include<iostream>
#include"book.hpp"
#include"novel.hpp"
#include"play.hpp"
#include"lms.hpp"

using namespace std;
void case3(LMS& sys,Book* x){
    if(sys.getBookType(x->getTitle()) == "Novel"){
        int option = 1;
        while(true){
            cout << "Enter 1 to Query,0 To quit\n";
            cin >> option;
            if(!option){
                Book* t = new Novel();
                *t = *x;
                sys.freeBook(t);
                break;
            }
            string word;
            int k,flag;
            cout << "Enter Word\n";
            cin  >> word;
            cout << "Enter 0 for Chapter query else 1 for Paragraphs\n";
            cin >>flag;
            cout << "Enter K for Top k queries\n";
            cin >> k;
            x->query(word,k,flag);
        }
    }
    else
    if(sys.getBookType(x->getTitle()) == "Play"){
        int option = 1;
        while(true){
            cout << "Enter 1 to Query,0 To quit\n";
            cin >> option;
            if(!option){
                Book* t = new Play();
                *t = *x;
                sys.freeBook(t);
                break;
            }
            string word;
            cout << "Enter Character\n";
            cin >> word;
            Play* t = dynamic_cast<Play*>(x);
            t->query(word);
        }
    }

}
void case2(LMS& sys){
    int option2 = 1;
    vector<Book*>books;
    while(option2){
        cout << "\nEnter 1 to List all Books\n";
        cout << "Enter 2 to Search for a Book\n";
        cout << "Enter 3 to Display a Book\n";
        cout << "Enter 4 to Select a Book for query\n";
        cout << "Enter 0 to Go Back\n";
        cin >> option2;
        switch(option2){
            case 1:
                sys.listBook();
                break;
            case 2:{
                books.clear();
                int option3 = 0;
                string keytype,key;
                cout << "Enter 1 for Nametype Search\n";
                cout << "Enter 2 for AuthorType Search\n";
                cin >>option3;
                if(option3 == 1)
                    keytype = strdup("name");
                else
                    keytype = strdup("author");
                cout << "Enter Search Key\n";
                cin >> key;
                books = sys.getBooks(key,keytype);
                for(Book* x:books){
                    cout << "Name: " << x->getTitle() << "\n";
                    cout << "Author: "<< x->getAuthor() << "\n\n";
                }
                break;
            }
            case 3:{
                cout << "Enter Book no. to display\n";
                int x;
                cin >> x;
                if(x-1 < books.size())
                    books[x-1]->printBook();
                break;
            }
            case 4:{
                cout << "Enter Book no. to query\n";
                int x;
                cin >> x;
                if(x-1 < books.size())
                {   books[x-1]->parseBook();
                    case3(sys,books[x-1]);
                }
                break;
            }
        } 
    }
}

int main(){
    string dir;
    cout << "Enter Book Directory";
    cin >>dir;
    LMS sys(dir);
    int option = 0,option2 = 0,option3 = 0;
    string key,keytype;

    while(option!=3){
        cout << "Enter 1 to Update System\n";
        cout << "Enter 2 to search/query Books\n";
        cout << "Enter 3 to exit system\n";
        cin >>option;
        switch (option){
            case 1:
                sys.updateSystem();
                break;
            case 2:
                case2(sys);
                break;
            case 3:
                break;
            default:
                cout << "Enter Valid Option\n";
                break;
        }
    }
}