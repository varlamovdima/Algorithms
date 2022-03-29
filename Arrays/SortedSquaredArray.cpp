#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array){
	for(int i=0;i<array.size();i++){
		array[i]=array[i]*array[i];
	}
	sort(array.begin(),array.end());
	return array;
}

void print(vector<int> array){
	for(int i=0;i<array.size();i++){
		cout<<array[i]<<endl;
	}
}

int main(){
	vector<int> arr = {-4,1,2,3,4,5,6,7,8,9};
	vector<int> result;
	result = sortedSquaredArray(arr);
	print(result);

	return 0;
}
