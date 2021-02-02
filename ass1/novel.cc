#include"novel.hpp"
using namespace std;
void Novel::query(const string&y,int k){
    string x = y;
    transform(x.begin(), x.end(), x.begin(), ::tolower);
    regex r(x);
    smatch m;
    priority_queue<pair<int,int>>cQ;
    priority_queue<pair<int,pair<int,int>>>pQ;
    int i = 1 ,j = 1;
    for(Chapter t:chapters){
        int sum = 0;
        j = 1;
        for(Paragraph p:t.paragraphs){
            int sum2 = 0;
            for(string line:p){
                string temp = line;
                transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
                regex_search(temp,m,r);
                sum2 +=m.size();
            }
            pQ.push(pair<int,pair<int,int> >{sum2,{i,j}});
            j++;
            sum +=sum2;
        }
        cQ.push(pair<int,int>{sum,i});
        i++;
    }
    for(int i = 0;i<k;i++){
        cout << cQ.top().first << " @ "<< cQ.top().second<<endl;
        cout << pQ.top().first << " @ " << pQ.top().second.first << "->" << pQ.top().second.second << endl;
        cQ.pop();
        pQ.pop();
    }
}

void Novel::parseBook(){
    cout << "herhe";
    ifstream file(getPath());
    if(file.is_open()){
        string line;
        int flag = 0;
        Paragraph p;
        while(getline(file,line)){
            if(line.substr(0,7) == "CHAPTER"){
                flag = 1;
                size_t pos = line.find(".");
                Chapter a;
                a.cno = stoi(line.substr(8,pos-7));
                a.cName = line.substr(pos+1);
                chapters.push_back(a);
                p.clear();
            }
            else
            if(flag == 1){
                if(line.size() == 0){
                    if(p.size() != 0)
                        chapters.back().paragraphs.push_back(p);
                    p.clear();
                }else
                p.push_back(line);
            }
        }
    }
}