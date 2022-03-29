#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution_0(vector<int> arr, int targetSum){	
	for(int i=0;i<arr.size()-1;i++){
		for(int j=1+i;j<arr.size();j++){
			if(arr[i]+arr[j]==targetSum) {
				result.push_back(arr[i]);
				result.push_back(arr[j]);
				found = true;
				return {arr[i],arr[j]};
			}
		}
	}
	found = false;
	return {};
}

vector<int> solution_1(vector<int> arr, int targetSum){	
	for(int i=0;i<arr.size()-1; i++){
		int secondNum=targetSum - arr[i];
		for(int j=1+i;j<arr.size();j++){
			if(secondNum==arr[j]){
				result.push_back(arr[i]);
				result.push_back(arr[j]);
				found=true;
				return {arr[i],arr[j]};
			}
		}
	}	
	return {};
}

vector<int> solution_2(vector<int> arr, int targetSum){	
	int left = 0;
	int right = arr.size()-1;
	sort(arr.begin(),arr.end());
	while(left<right){
		if(arr[left]+arr[right]>targetSum){
			right--;	
		} else if(arr[left]+arr[right]<targetSum){
			left++;
		}else {
		result.push_back(arr[left]);
		result.push_back(arr[right]);
		found=true;
		return {arr[left],arr[right]};
		}
	}
	return {};
}

void print_result(){
	if(found){
		for(int i=0;i<result.size();i++){
			cout<<result[i]<<" ";
		}
		cout<<endl;
	} else {
		cout<<"The pair is not found!"<<endl;
	}
}

int main() {


	return 0;
}

