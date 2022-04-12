#include <iostream>
#include <vector>
using namespace std;

vector<int> arrayOfProducts(vector<int> arr){
	int index = 0;
	int temp = 1;
	vector<int> result;
	while(index<arr.size()){
		temp=1;
		for(int i=0;i<arr.size();i++){
			if(i!=index)
				temp=temp*arr[i];	
		}
		result.push_back(temp);
		index++;
	}


	return result;
}

int main(){
	vector<int> arr{5,1,4,2};
	vector<int> result = arrayOfProducts(arr);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<' ';
	}
	cout<<endl;
	return 0;
}
