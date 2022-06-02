#include<vector>
#include<iostream>
using namespace std;

int binarySearch(vector<int> array, int target, int leftPtr, int rightPtr){
	int middlePtr;
	while(leftPtr<=rightPtr){
		middlePtr = (leftPtr + rightPtr)/2;
		if(array[middlePtr] == target)
			return middlePtr;
		else if(array[middlePtr] < target)
			leftPtr = middlePtr + 1;
		else if(array[middlePtr]>target)
			rightPtr = middlePtr - 1;	
	}
	return -1;
}

int findLeftExt(vector<int> array, int target){
	int leftPtr = 0;
	int rightPtr = array.size()-1;
	
	int mid = binarySearch(array,target,leftPtr,rightPtr);
	while(mid>=0){
		if(mid == 0 || array[mid-1]!=target)
			return mid;
		else{
			rightPtr = mid - 1;
	 		mid = binarySearch(array,target,leftPtr,rightPtr);
		}
	}
	return -1;
}

int findRightExt(vector<int> array, int target){
	int leftPtr = 0;
	int rightPtr = array.size()-1;
	
	int mid = binarySearch(array,target,leftPtr,rightPtr);
	while(mid>=0){
		if(mid == array.size()-1 || array[mid+1]!=target)
			return mid;
		else{
			leftPtr = mid + 1;
	 		mid = binarySearch(array,target,leftPtr,rightPtr);
		}
	}
	return -1;
	
}

vector<int> searchForRange(vector<int> array, int target){
	return {findLeftExt(array,target),findRightExt(array,target)};
}

int main(){
	vector<int> array{0,1,21,33,45,45,45,45,45,45,61,71,73};
	int target = 45;
	vector<int> result = searchForRange(array,target);
	cout<<result[0]<<","<<result[1]<<endl;
	return 0;
}
