#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a=b;
	b=temp;
}

vector<int> selectionSort(vector<int> array){
	int index=0;
	int sortedIndex=0;
	while(sortedIndex<array.size()-1){
	int min = array[sortedIndex];
	for(int i=sortedIndex;i<array.size();i++){
		if(array[i]<min){
			index=i;
			min=array[i];
		}

	}
	if(min==array[sortedIndex]){
		
	}else{
		swap(array[sortedIndex],array[index]);
	}
	sortedIndex++;
	}

	return array;
}

int main(){
	vector<int> array{3,1,2};
	vector<int> result = selectionSort(array);

	for(int i=0;i<result.size();i++){
		cout<<result[i]<<' ';
	}
	cout<<endl;
	return 0;
}
