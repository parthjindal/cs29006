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
}