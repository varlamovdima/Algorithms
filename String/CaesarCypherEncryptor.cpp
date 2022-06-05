#include <vector>
#include <numeric>
#include <string>
#include <iostream>
using namespace std;

char getNewLetter(char letter, int key);

string caesarCypherEncryptor(string str, int key) {
  vector<char> newLetters;
  int newKey = key%26;
  for(int i=0;i<str.size();i++){
    newLetters.push_back(getNewLetter(str[i], newKey));
  }
  return string(newLetters.begin(),newLetters.end());
}

char getNewLetter(char letter, int key){
  int newLetterCode = letter + key;
  return newLetterCode <= 122 ? newLetterCode : 96+newLetterCode % 122;
}

int main(void){
    string str = "abc";
    int key = 1;
    cout<<caesarCypherEncryptor(str,key)<<endl;
    return 0;
}
