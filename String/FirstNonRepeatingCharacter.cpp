// First Non-Repeating Character
// Write a fucntion that takes in a string of lowercase English-alphaber letters and 
// returns the index of the string's first non-repeating character
//
// The first non-repeating character is the first character in a string that occurs only once.
// If the input string doesn't have any non-repeating characters, your function should return -1
//
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int firstNonRepeatingCharacter(string str){
	int count = 0;
	vector<int> arr;
	for(int i=0;i<str.size();i++){		
			for(int j=0;j<str.size();j++){
				if(str[i]==str[j])
					count++;
			}
		
		arr.push_back(count);
		count = 0;
	}
	for(int i=0;i<arr.size();i++){
		if(arr[i]==1)
			return i;
	}
	return -1;
}

int main(void){
	string str = "abcdcaf";
	cout<<firstNonRepeatingCharacter(str)<<endl;
	return 0;
}
