#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals){
	sort(intervals.begin(),intervals.end(),
			[](vector<int> a,vector<int> b){return a[0]<b[0];});
	
	vector<vector<int>> result;
	for(int i=0;i<intervals.size()-1;i++){
		vector<int> first = intervals[i];
		vector<int> second = intervals[i+1];
		if(first[1]>=second[0]){
			vector<int> temp{first[0],second[1]};
			cout<<"Merging"<<endl;
			cout<<"Creating temp variable "<<temp[0]<<' '<<temp[1]<<endl;
			i++;
			while(temp[1]>=intervals[i+1][0]){
				temp[1]=intervals[i+1][1];
				cout<<"Updating temp variable "<<temp[0]<<' '<<temp[1]<<endl;
				
				i++;
			}
			result.push_back(temp);
			if((i+1)==(intervals.size()-1)){
				result.push_back(intervals[i+1]);
				cout<<"Adding the last element "<<intervals[i+1][0]<<' '<<intervals[i+1][1]<<endl;
				break;
			}
			i--;
		}else
			result.push_back(first);
			cout<<"Adding to the output "<<first[0]<<' '<<first[1]<<endl;
			

	}
	return result;
}

int main(){
	vector<vector<int>> intervals{{1,2},{3,5},{4,7},{6,8},{9,10}};
	for(int i=0;i<intervals.size();i++){
		for(int j=0;j<intervals[i].size();j++){
			cout<<intervals[i][j]<<' ';
		}
		cout<<endl;
	}
	vector<vector<int>> result=mergeOverlappingIntervals(intervals);
	
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}
