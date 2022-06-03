#include<iostream>
#include<vector>
using namespace std;

void swap(int leftIdx, int rightIdx, vector<int> &array){
	int temp = array[leftIdx];
	array[leftIdx] = array[rightIdx];
	array[rightIdx] = temp;
}

int quickselectHelper(vector<int> array,int startIdx,int endIdx,int position){
	while(true){
		int pivotIdx = startIdx;
		int leftIdx = startIdx + 1;
		int rightIdx = endIdx;
		while(leftIdx<=rightIdx){
			if(array[leftIdx]>array[pivotIdx] && array[rightIdx] < array[pivotIdx]){
				swap(leftIdx,rightIdx ,array);
			}
			if(array[leftIdx] <= array[pivotIdx]){
				leftIdx++;
			}
			if(array[rightIdx] >= array[pivotIdx]){
				rightIdx--;
			}
		}
		swap(pivotIdx,rightIdx,array);
		if(rightIdx==position)
			return array[rightIdx];
		else if(rightIdx<position)
			startIdx = rightIdx + 1;
		else
			endIdx = rightIdx - 1;		
	}
}

int quickselect(vector<int> array, int k){
	int position = k - 1;
	return quickselectHelper(array, 0, array.size() - 1, position);
}

int main(){
	vector<int> array{8,5,2,9,7,6,3};
	cout<<quickselect(array,3)<<endl;
	return 0;
}
