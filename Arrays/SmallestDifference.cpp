#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
	sort(arrayOne.begin(),arrayOne.end());
	sort(arrayTwo.begin(),arrayTwo.end());
	int diff;
	
	vector<int> result{0,0};
	diff = abs(arrayOne[0]-arrayTwo[0]);
	for(int i=0;i<arrayOne.size();i++){
		for(int j=0;j<arrayTwo.size();j++){
			
			if(diff>abs(arrayOne[i]-arrayTwo[j])){
				diff = abs(arrayOne[i]-arrayTwo[j]);
				result[0]=arrayOne[i];
				result[1]=arrayTwo[j];
			}
		}
	}

	return result;
}
int main() {
	vector<int> arrayOne{-1,5,10,20,28,3};
	vector<int> arrayTwo{26,134,135,15,17};
	
	vector<int> result = smallestDifference(arrayOne,arrayTwo);
	for(auto i:result){
		cout<<i<<endl;
	}

	return 0;
}
