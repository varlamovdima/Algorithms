#include <iostream>
#include <vector>
using namespace std;
int longestPeak(vector<int> arr){
	bool left = true;
	bool right = true;
	int peakSize=0;
	int newPeakSize =0;
	for(int i=1;i<arr.size()-1;i++){
		if(arr[i-1]<arr[i] && arr[i]>arr[i+1]){
			left=true;
			right =true;
			peakSize = 1;
			int j=0;
			while(left||right){
				if((i-j-1)>=0 && (i+j+1)<arr.size()){

				if(arr[i-j-1]<arr[i-j] && left){
					peakSize++;
					left=true;
				}else{
					left = false;
				}	
				if(arr[i+j]>arr[i+j+1] && right){
					peakSize++;
					right=true;
				}
				else{
					right = false;
				}
				j++;

				}
			}
			
			if(peakSize>newPeakSize)
				newPeakSize = peakSize;
		}

	}
	
	return newPeakSize;
}

int main(){
	vector<int> arr{1,2,3,3,4,0,10,6,5,-1,-3,2,2};
	int result = longestPeak(arr);
	cout<<result<<endl;
	return 0;
}

