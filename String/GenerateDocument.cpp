#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool generateDocument(string characters, string document) {
    unordered_map<char,int> map, map1;
    for(int i=0;i<document.size();i++){
        if( map.find (document[i]) != map.end() )
            ++(map.find (document[i])->second);
        else
            map[document[i]]=1;
    }
    for(int i=0;i<characters.size();i++){
        if( map1.find (characters[i]) != map1.end() )
            ++(map1.find (characters[i])->second);
        else
            map1[characters[i]]=1;
    }

    for(auto it=map.begin();it!=map.end();it++) {
        if(map1[it->first]<it->second){
            return false;
        } 
    }
  return true;
}

int main() {
    string characters = "Best";
    string document = "Best";
    cout<<generateDocument(characters,document)<<endl;

    // unordered_map<char,int> map;
    // map['A'] = 1;
    // map['B'] = 2;
    // //unordered_map<string,int>::const_iterator got = map.find ('A');
    // if( map.find ('A') != map.end() ){
    //     cout<<++(map.find ('A')->second)<<endl;
    // }
    // //cout<<map[document[0]]<<endl;
    // //cout<<map.find(document[0])<<endl;
    return 0;
}
