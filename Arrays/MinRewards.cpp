#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minRewards(vector<int> array){
	vector<int> scores(array.size(),1);
	
	for(int i=0;i<array.size()-1;i++){
		
		if(array[i]>array[i+1]){
			int counter = i;				
			if(scores[i]>scores[i+1]){
			
			}else{
				while(counter >= 0){
					scores[counter]++;
					counter--;
				}
			}
		
		}else{
			scores[i+1]=scores[i]+1;
			
		}
	}
	int result = 0;
	for(int i=0;i<scores.size();i++){
		result=result+scores[i];
	}
	return result;
}


int minRewards1(vector<int> array){
	vector<int> scores(array.size(),1);
	for(int i=1;i<array.size();i++){
		if(array[i-1]<array[i]){
			scores[i]=scores[i-1]+1;
		}
	}

	for(int i=array.size()-2;i>=0;i--){
		if(array[i]>array[i+1]){
			scores[i]=max(scores[i+1]+1,scores[i]);
		}
	}
	int result = 0;
	for(int i=0;i<scores.size();i++){
		cout<<scores[i]<<' ';
		result = result + scores[i];
	}
	cout<<endl;
	return result;

}

int main() {
	vector<int> array{8,4,2,1,3,6,7,9,5};//5
	cout<<"Result "<<minRewards1(array)<<endl;
	return 0;
}
