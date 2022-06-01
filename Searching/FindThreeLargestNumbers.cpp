#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void shiftAndUpdate(vector<int> &result, int num, int idx){
	for(int i=0;i<3;i++){
		if(i==idx)
			result[i] = num;
		else
			result[i] = result[i+1];
	}
}

void updateLargest(vector<int> &result, int num){
	if(num > result[2]){
		shiftAndUpdate(result, num ,2);
	}else if(num > result[1]){
		shiftAndUpdate(result, num, 1);
	}else if(num > result[0]){
		shiftAndUpdate(result, num, 0);
	}
}

vector<int> findThreeLargestNumbers(vector<int> array){
	vector<int> result(3, INT_MIN);
	for(int i=0;i<array.size();i++){
		updateLargest(result, array[i]);
	}	

	return result;
}

int main(){
	vector<int> array{141,1,17,-7,-17,-27,18,541,8,7,7};
	vector<int> result = findThreeLargestNumbers(array);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<' ';
	}
	cout<<endl;
	return 0;
}
