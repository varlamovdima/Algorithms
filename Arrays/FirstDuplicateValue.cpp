#include<iostream>
#include<vector>
#include<map>
using namespace std;

int firstDuplicateValue(vector<int> arr){
	map<int,int> table;
	for(int i=0;i<arr.size();i++){
		if(table.find(arr[i])!=table.end())
			return arr[i];
		else
			table.insert(pair<int,int>(arr[i],1));
	
	}
	return -1;
}

int main(){
	vector<int> arr{2,1,5,2,3,3,4};
	int result = firstDuplicateValue(arr);
	cout<<result<<endl;
	return 0;
}
