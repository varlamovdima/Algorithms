#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> coins){
	sort(coins.begin(),coins.end());
	int currentChangeCreated = 0;
	for(int coin:coins){
		if(coin>currentChangeCreated+1)
			return currentChangeCreated+1;
		currentChangeCreated +=coin;
	}
	return currentChangeCreated + 1;
}


int main(){
	
	vector<int> coins = {5,7,1,1,2,3,22};
	int result;
	result = nonConstructibleChange(coins);
	cout<<result<<endl;
	return 0;
}
