#include <iostream>
#include <vector>
using namespace std;

bool isMonotonic(vector<int> arr){
	if(arr.size()==0||arr.size()==1)
		return true;
	vector<bool> dec;
	vector<bool> inc;
	bool isInc = true;
	bool isDec = true;	
	for(int i=0;i<arr.size()-1;i++){
		if(arr[i]>=arr[i+1]){
			dec.push_back(true);
		}else
			dec.push_back(false);
		
		if(arr[i]<=arr[i+1]){
			inc.push_back(true);
		}else
			inc.push_back(false);
	}

	for(int i=0;i<dec.size();i++){
		if(dec[i]==false)
			isDec = false;
	}
	for(int i=0;i<inc.size();i++){
		if(inc[i]==false)
			isInc = false;
	}
	if(isInc||isDec==true)
		return true;
	else
		return false;
}

int main(){
	bool result;
	vector<int> arr{-1,-5,-10,-1100,-1100,-1101,-1102,-9001};
	result = isMonotonic(arr);
	cout<<result<<endl;
	return 0;
}
