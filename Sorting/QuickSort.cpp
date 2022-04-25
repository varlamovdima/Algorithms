#include <iostream>
#include <vector>
using namespace std;

void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}

void print(vector<int> array){
	for(auto&i:array){
		cout<<i<<' ';
	}
	cout<<endl;
}


void quickSortHelper(vector<int> &array,int startIndex,int endIndex){
	int p=startIndex;
	int l=p+1;
	int r=endIndex;;
	if(p>=r)
		return;

	while(r>=l){
		if(array[r]<array[p] && array[l]>array[p]){
			swap(array[r],array[l]);	
		}
		if(array[l]<=array[p]){
			l++;
		}
		if(array[r]>=array[p]){
			r--;
		}
	}
	swap(array[r],array[p]);
	bool isSmaller = r - 1 - startIndex <endIndex - (r+1);
	if(isSmaller){
		quickSortHelper(array,startIndex,r-1);
		quickSortHelper(array,r+1,endIndex);
	}else{
		quickSortHelper(array,r+1,endIndex);
		quickSortHelper(array,startIndex,r-1);
		
	}
}
vector<int> quickSort(vector<int> &array){
	quickSortHelper(array,0,array.size()-1);
	return array;
}

int main(){
	vector<int> array{8,5,2,9,5,6,3};
	vector<int> result = quickSort(array);
	print(result);
	return 0;
}
