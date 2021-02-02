#include "book.hpp"
#include <vector>
#include <string>
#include<fstream>
#include<regex>
#include <set>
typedef std::set<std::string> scene;

using namespace std;

class Play : public Book{
    std::vector<scene> scenes;
public:
    Play();
    void parseBook();
    void query(const string &);
};
