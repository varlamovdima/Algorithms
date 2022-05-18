#include <iostream>
#include <vector>
#include <math.h>
using namespace std;



void swap(int i,int j, vector<int> &heap){
	int temp = heap[i];
	heap[i]=heap[j];
	heap[j] = temp;
}

void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
	int childOneIdx = currentIdx*2+1;
	int childTwoIdx;
	int idxToSwap;
	while(childOneIdx<=endIdx){
		if((currentIdx*2+2)<=endIdx)
			childTwoIdx = currentIdx*2+2;
		else
			childTwoIdx = -1;
		if(childTwoIdx!=-1 && heap[childTwoIdx]>heap[childOneIdx])
			idxToSwap = childTwoIdx;
		else
			idxToSwap = childOneIdx;

		if(heap[idxToSwap]>heap[currentIdx]){
			swap(currentIdx,idxToSwap,heap);
			currentIdx=idxToSwap;
			childOneIdx = currentIdx*2+1;
		}else
			break;
		
	}
}

void buildHeap(vector<int> &vector) {
	int firstParentIdx = floor((vector.size()-1)/2);
	for(int i = vector.size()-1;i>=0;i--){
		siftDown(i,vector.size()-1,vector);
	}
	
}

vector<int> heapSort(vector<int> array){
	int sorted = 1;
	buildHeap(array);
	swap(0,array.size()-sorted,array);

	while(sorted<=array.size()-1){
		sorted++;
		siftDown(0,array.size()-sorted, array);
		swap(0,array.size()-sorted,array);
	}
	
	return array;
}

int main(){
	vector<int> heap = {1,2,4,3,7,9,4,3,2};
	vector<int> result = heapSort(heap);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<' ';
	}
}
