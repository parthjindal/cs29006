#include "book.hpp"
#include "logger.hpp"
#include <vector>
#include <string>
#include<set>
typedef std::set<std::string> scene;
using namespace std;

class Play: public Book{
    std::vector<scene> scenes;
   public:
    void parseBook(const string& fileName) ;
    void printBook();
    void query(const string&,int);
};
