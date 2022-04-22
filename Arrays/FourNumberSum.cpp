#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> arr, int targetSum){
	unordered_map<int,vector<vector<int>>> allPairSums;
	vector<vector<int>> quadruplets ={}; 
	for(int i=1;i<arr.size()-1;i++){
		for(int j=i+1;j<arr.size();j++){
			int currentSum=arr[i]+arr[j];
			int difference=targetSum-currentSum;
			if(allPairSums.find(difference)!=allPairSums.end()){
				for(vector<int> pair : allPairSums[difference]){
					pair.push_back(arr[i]);
					pair.push_back(arr[j]);
					quadruplets.push_back(pair);
				}
			}
		}
		for(int k=0;k<i;k++){
			int currentSum = arr[i]+arr[k];
			if(allPairSums.find(currentSum)==allPairSums.end()){
				allPairSums[currentSum]=vector<vector<int>>{{arr[k],arr[i]}};
			}else{
				allPairSums[currentSum].push_back(vector<int>{arr[k],arr[i]});
			}
		}

	
	}


	return quadruplets;
}

int main() {
	vector<int> arr{7,6,4,-1,1,2};
	int targetSum = 16;
	vector<vector<int>> result = fourNumberSum(arr, targetSum);

	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<',';
		}
		cout<<endl;
	}
	cout<<endl;

	return 0;
}
