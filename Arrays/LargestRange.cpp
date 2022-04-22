#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> largestRange(vector<int> array){
	unordered_map<int,bool> table;
	vector<int> finalRange;
	for(int i=0;i<array.size();i++){
		table.insert({array[i],true});	
	}
	for(int i=0;i<array.size();i++){
		vector<int> range{};
		int num = array[i];
		
		if(table[num]==true){

		table[num]=false;
		range.push_back(array[i]);
		
		int right = num + 1;
		int left = num - 1;
		bool rightDone = true;
		bool leftDone = true;
		while(rightDone || leftDone){
		unordered_map<int,bool>::const_iterator gotRight = table.find(right);
		unordered_map<int,bool>::const_iterator gotLeft = table.find(left);
			if(gotRight != table.end()){
				table[right]=false;
				range.push_back(right);
				right++;
			}else
				rightDone=false;
			if(gotLeft != table.end()){
				table[left]=false;
				range.insert(range.begin(),left);
				left--;
			}else
				leftDone=false;
		}
		}
		if(range.size()>finalRange.size()){
			finalRange=range;
		}	
	}
	return vector<int>{finalRange[0],finalRange[finalRange.size()-1]};
}

int main(){
	vector<int> array{1,11,3,0,15,5,2,4,10,7,12,6};
	vector<int> result = largestRange(array);
	cout<<result[0]<<","<<result[1]<<endl;
	return 0;
}
