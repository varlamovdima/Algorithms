// Men heap mean that the root node has the smallest value in the tree
// 			8
// 		  /   \
// 		12     23
// 	   /  \   /  \
// 	  17  31 30  44
// 	 / \ 
// 102  18  

// i - root node
// i*2 + 1 - left child node
// i*2 + 2 - right child node
// floor((i-1)/2) - find parent node of a node at index i
// [8,12,23,17,31,30,44,102,18]

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#include <vector>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
public:
vector<int> heap;

MinHeap(vector<int> vector) { heap = buildHeap(vector); }

vector<int> buildHeap(vector<int> &vector) {
	int firstParentIdx = floor((vector.size()-1)/2);
	for(int i = vector.size()-1;i>=0;i--){
		siftDown(i,vector.size()-1,vector);
	}
	return vector;
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
		if(childTwoIdx!=-1 && heap[childTwoIdx]<heap[childOneIdx])
			idxToSwap = childTwoIdx;
		else
			idxToSwap = childOneIdx;

		if(heap[idxToSwap]<heap[currentIdx]){
			swap(currentIdx,idxToSwap,heap);
			currentIdx=idxToSwap;
			childOneIdx = currentIdx*2+1;
		}else
			break;
		
	}
}

void siftUp(int currentIdx, vector<int> &heap) {
	int parentIdx = floor((currentIdx-1)/2);
	while(currentIdx>0 && heap[currentIdx]<heap[parentIdx]){
		swap(currentIdx,parentIdx,heap);
		currentIdx=parentIdx;
		parentIdx = floor((currentIdx-1)/2);
	}
}

int peek() {
	return heap[0];
}

int remove() {
	swap(0,heap.size()-1,heap);
	int value = heap[heap.size()-1];
	heap.pop_back();
	siftDown(0,heap.size()-1,heap);
	return value;
}

void insert(int value) {
	heap.push_back(value);
	siftUp(heap.size()-1, heap);
}

void swap(int i,int j, vector<int> &heap){
	int temp = heap[i];
	heap[i]=heap[j];
	heap[j] = temp;
}

};

int main(){
	return  0;
}