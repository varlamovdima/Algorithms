#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralTraverse(vector<vector<int>> arr){
	int sC=0;
	int eC=arr[0].size()-1;
	int sR=0;
	int eR=arr.size()-1;
	int counter=0; 
	vector<int> result;
	while(counter<arr.size()*arr[0].size()){
	//first pass
	for(int i=sC;i<=eC;i++){
		result.push_back(arr[sR][i]);
		counter++;
	}
	if(sR!=eR){
	//second pass	
	for(int i=sR+1;i<=eR;i++){
		result.push_back(arr[i][eC]);
		counter++;
	}
	
	//third pass
	for(int i=eC-1;i>=sC;i--){
		result.push_back(arr[eR][i]);
		counter++;
	}
	if(sC!=eC){
	//forth pass
	for(int i=eR-1;i>=sR+1;i--){
		result.push_back(arr[i][sC]);
		counter++;
	}
	}
	}
	sC++;
	eC--;
	sR++;
	eR--;
	}
	return result;
}

int main(){
	vector<vector<int>> arr{{1,2,3,4},
				{12,13,14,5},
				{11,16,15,6},
				{10,9,8,7}};
	vector<int> result = spiralTraverse(arr);

	for(int i=0;i<result.size();i++){
		cout<<result[i]<<' ';
	}
	cout<<endl;
	return 0;
}
