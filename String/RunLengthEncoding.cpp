#include <vector>
#include <string>
#include <iostream>
using namespace std;

string runLengthEncoding(string str){
  vector<char> encodedStringCharacters;
  int currentRunLength = 1;

  for(int i=1;i<str.size();i++){
    char currentCharacter = str[i];
    char previousCharacter = str[i-1];

    if(currentCharacter != previousCharacter || currentRunLength == 9){
      encodedStringCharacters.push_back(to_string(currentRunLength)[0]);
      encodedStringCharacters.push_back(previousCharacter);
      currentRunLength = 0;
    }
    currentRunLength++;
    }
    encodedStringCharacters.push_back(to_string(currentRunLength)[0]);
    encodedStringCharacters.push_back(str[str.size()-1]);

string encodedString(encodedStringCharacters.begin(), encodedStringCharacters.end());
   return encodedString;
}


int main(){
	string str = "AAAAAAAAAAAABBBCCCDD";
	cout<<runLengthEncoding(str)<<endl;
	return 0;
}