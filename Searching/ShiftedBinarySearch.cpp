#include<iostream>
#include<vector>
using namespace std;

int shiftedBinarySearch(vector<int> array, int target) {
	int leftPtr = 0;
	int rightPtr = array.size()-1;
	int middlePtr;
	while(leftPtr<=rightPtr){
		middlePtr = (leftPtr+rightPtr)/2;
		if(array[middlePtr] == target)
			return middlePtr;
		if(array[leftPtr]<=array[middlePtr]){
			if(target<array[middlePtr] && target >= array[leftPtr]){
			//explore left side
				rightPtr = middlePtr - 1;
			}else{
			//explore right side
				leftPtr = middlePtr + 1;
			}
		}else{
			if(target < array[leftPtr]){		
				// we can explore right side
				leftPtr = middlePtr + 1;
			}else{
				rightPtr = middlePtr - 1;
			}
		}
	}
	return -1;
}

int main(){
	vector<int> array{45,61,71,72,73,0,1,21,33,45};
	cout<<shiftedBinarySearch(array,33)<<endl;
	return 0;
}
