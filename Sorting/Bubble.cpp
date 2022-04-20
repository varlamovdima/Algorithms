#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

vector<int> bubbleSort(vector<int> array){
	if(array.empty())
		return {};
	bool isSorted;
	int counter = 0;
	while(!isSorted){
		isSorted = true;
		for(int i = 0;i<array.size()-1-counter;i++){
			if(array[i]>array[i+1])
				swap(array[i],array[i+1]);
			isSorted = false;
		}
		counter++;
	}
	return array;
}

void print(vector<int> array){
	for(int i=0;i<array.size();i++)
		cout<<array[i]<<' ';
	cout<<endl;
}

int main(){
	vector<int> array{8,5,2,9,5,6,3};
	print(array);
	print(bubbleSort(array));
	return 0;
}
