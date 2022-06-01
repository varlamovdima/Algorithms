#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target) {
	int leftPtr = 0;
	int rightPtr = array.size()-1;
	int middlePtr;
	while(leftPtr<=rightPtr){
		middlePtr = (leftPtr+rightPtr)/2;
		if(array[middlePtr]==target)
			return middlePtr;
		else if(array[middlePtr]>target){
			// look on the left side
			rightPtr = middlePtr - 1;
		
		}else if(array[middlePtr]<target){
			// look on the right side
			leftPtr = middlePtr + 1;
		}
	}
	return -1;
}

int main(){
	vector<int> array{0,1,21,33,45,45,61,71,72,73};
	int target = 33;
	int result = binarySearch(array,target);
	cout<<result<<endl;
	return 0;
}
