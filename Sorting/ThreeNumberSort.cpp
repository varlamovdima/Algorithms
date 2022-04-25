#include <iostream>
#include <vector>
using namespace std;

void swap(int &a,int &b){
	int temp=a;
	a=b;
	b=temp;
}

vector<int> threeNumberSort(vector<int> array, vector<int> order){
		
	int firstIndex=0;
	int lastIndex=array.size()-1;
	for(int i=0;i<array.size();i++){
		if(array[i]==order[0]){
			swap(array[i],array[firstIndex]);
			firstIndex++;
		}

	}
	for(int i=array.size()-1;i>=0;i--){
		if(array[i]==order[2]){
			swap(array[i],array[lastIndex]);
			lastIndex--;
			if(lastIndex==firstIndex)
				break;
		}
	}

	return array;
}
vector<int> threeNumberSort1(vector<int> array, vector<int> order){
	int first=0;//1
	int second=0;
	int third = array.size()-1;

	while(second<=third){
		if(array[second]==order[1]){
			second++;
			continue;
		}

		if(array[second]==order[0]){
			swap(array[second],array[first]);
			first++;
			second++;
			continue;
		}
		if(array[second]==order[2]){
			swap(array[second],array[third]);
			third--;
			continue;
		}
	}	
	return array;

}

int main(){
	vector<int> array{1,0,0,-1,-1,0,1,1};
	vector<int> order{0,1,-1};
	vector<int> result = threeNumberSort1(array,order);
	for(int i=0;i<result.size();i++){
		cout << result[i] <<' ';
	}
	cout<<endl;

	return 0;
}
