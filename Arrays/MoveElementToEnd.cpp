#include <iostream>
#include <vector>
using namespace std;

vector<int> moveElementToEnd(vector<int> arr, int toMove){
	int right = arr.size()-1;
	int left = 0;
	
	while(left<right){
	if(arr[right]==toMove){
		right--;
	}else if(arr[left]==toMove){
		// Swap
		arr[left]=arr[right];
		arr[right]=toMove;
		right--;
		left++;
	}else if(arr[left]!=toMove){
		left++;
	}
	}
	return arr;
}

int main(){
	vector<int> arr{2,1,2,2,2,3,4,2};
		//	4,1,3,2,2,2,2,2
	vector<int> result = moveElementToEnd(arr,2);
	for(auto i:result){
		cout<<i<<' ';
	}
	cout<<endl;

	return 0;
}
