#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> &arr, int targetSum){
	sort(arr.begin(),arr.end());
	vector<vector<int>> result;
	for(int i=0;i<arr.size()-2;i++){
	int left = i+1;
	int right=arr.size()-1;
		while(left<right){
		int cs=arr[i]+arr[left]+arr[right];
		if(cs==targetSum){
			result.push_back({arr[i],arr[left],arr[right]});
			left++;
			right++;
		}else if(cs>targetSum){
			right--;
		}else if(cs<targetSum){
			left++;
		}

	}
	}
	return result;
}

int main(){
	vector<int> arr{12,3,1,2,-6,5,-8,6};
	int targetSum = 0;
	vector<vector<int>> result;
	result = threeNumberSum(arr,targetSum);

	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;
	return 0;
}
