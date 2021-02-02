#include<iostream>
#include"book.hpp"
#include"logger.hpp"
#include"novel.hpp"
#include"lms.hpp"

using namespace std;

int main(){
    LMS x;
    x.updateSystem("/home/parth/cs29006/files");
    x.listBook();
    string a("moby"),b("name");
    vector<Book*> q = x.getBooks(a,b);
    for(Book* m:q){
        x.deleteBook(m);
    }
    x.listBook();
    
}