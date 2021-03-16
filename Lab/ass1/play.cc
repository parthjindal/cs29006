#include "play.hpp"

Play::Play(){

}

void Play::parseBook(){
    using namespace std;
    ifstream file(getPath());
    string line;
    scene s;
    smatch m;
    if(scenes.empty() == 0)
        scenes.clear();

    regex r("^[A-Z]+\\s{0,1}[A-Z]*\\.");
    if(file.is_open()){
        while(getline(file, line)){
            if(line.substr(0, 6) == "CHORUS")
                continue;
            if(line.substr(0, 5) == "SCENE"){
                if(!s.empty()){
                    scenes.push_back(s);
                    s.clear();
                }
                continue;
            }
            regex_search(line, m, r);
            if(m.size()){
                for(auto x : m)
                    s.insert(x);
            }
        }
    }
    if(!s.empty()){
        scenes.push_back(s);
        s.clear();
    }
}

void Play::query(const string&x){
    string q = x;
    transform(q.begin(), q.end(), q.begin(), ::toupper);
    q = q + ".";
    set<string> queried;
    int count = 0;
    for(scene a : scenes){   
        if(a.find(q) != a.end()){
            for(string role : a){
                if(role != q)
                    queried.insert(role);
            }
            count++;
        }
    }
    if(!count){
        cout<<"\nNo matches found\n";
        return;
    }
    cout<<"\nList of all characters that come in atleast one scene with "<<q<<" is : \n";
    for(string x: queried)
        cout << x <<"\n";
    return;
}