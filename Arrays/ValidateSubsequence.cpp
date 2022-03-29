// This program find sequence in an array
// By: Dmitrii Varlamov

#include <iostream>
#include <vector>

using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence){
	int ptr=0;
	for(int i=0;i<array.size();i++){
		if(array[i]==sequence[ptr])
			ptr++;
	}
	if(ptr==sequence.size())
		return true;
	return false;
}


int main(){
	bool isValid = isValidSubsequence({1,2,3,4,5},{1,2,3});	
	cout<<isValid<<endl;
	return 0;
}
