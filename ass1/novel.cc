#include"novel.hpp"

void Novel::query(const std::string&y,int k,int flag){
    using namespace std;
    string x = y;
    transform(x.begin(), x.end(), x.begin(), ::tolower);
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
                stringstream words(temp);
                string word;
                while(getline(words,word,' ')){
                    if(word == x)
                        sum2++;
                    else
                    if(word.back() == ',' ||
                     word.back() == '.' | word.back() == ';'||
                     word.back() == '?' || word.back() == '!'){
                         if(word == (x+word.back()))
                            sum2++;
                    }  
                }
            }
            pQ.push(pair<int,pair<int,int> >{sum2,{i,j}});
            j++;
            sum +=sum2;
        }
        cQ.push(pair<int,int>{sum,i});
        i++;
    }
    if( flag == 0){
        for(int i = 0;i<k;i++){
            cout << "\nOccurences: " << cQ.top().first << "\n";
            printChapter(cQ.top().second);
            cQ.pop();
        }
    }
    else
    {
        for(int i = 0;i<k;i++){
            cout << "\nOccurences: " << pQ.top().first;
            cout << "CHAPTER: " << pQ.top().second.first << "PARAGRAPH: " << pQ.top().second.second << "\n";
            for(string line:chapters[pQ.top().second.first -1].paragraphs[pQ.top().second.second-1])
                cout << line << "\n";      
            pQ.pop();
        }
    }

}

void Novel::printChapter(int i){
    using namespace std;
    cout << "CHAPTER :" << i << chapters[i-1].cName <<"\n";
    int count = 0;
    for(Paragraph p:chapters[i-1].paragraphs){
        cout << "\n";
        for(string line:p){
            cout << line << "\n";
            count++;
        }
        if(count >= 50){
        return;
        }
    } 
}

void Novel::parseBook(){
    using namespace std;
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