#include <vector>
#include <iostream>
using namespace std;
void swap(int& a,int& b){
	int temp = a;
	a = b;
	b = temp;
}

void print(vector<int> array){
	for(int i=0;i<array.size();i++){
		cout<<array[i]<<' ';
	}
	cout<<endl;
}

vector<int> insertionSort(vector<int> array){
	if(array.empty())
		return {};
	for(int i=1;i<array.size();i++){
		int j=i;
		while(j>0 && array[j-1]>array[j]){
			swap(array[j-1],array[j]);
			j--;
		}
	}
	return array;	

}

int main() {
	vector<int> array{8,5,2,9,5,6,3};
	print(array);
	print(insertionSort(array));
	return 0;
}
