#include <vector>
#include <iostream>

using namespace std;
vector<int> zigzagTraverse(vector<vector<int>> array) {
        vector<int> result;
 	int size = array.size() * array[0].size();
	bool dir = true; // true - down, false - up
	
	int lastRow = array.size()-1;
	int lastCol = array[0].size()-1;
	
	int row = 0;
	int col = 0;
	while(result.size()<size){
		// Direction is down
		if(dir==true){
		// Check left and bottom boundaries
			if(row!=lastRow && col==0){
				result.push_back(array[row][col]);
				row++;
				dir = false;
				continue;
			}
			if(row!=lastRow && col!=0){
				result.push_back(array[row][col]);
				row++;
				col--;
				dir = true;
				continue;
			}
			if(row==lastRow && col!=0){
 				result.push_back(array[row][col]);
				col++;
				dir = false;
				continue;
			}
			
			if(row==lastRow && col==lastCol){
				result.push_back(array[row][col]);
				break;
			}
		}else{
			// Check right and top bondaries
			if(row!=0 && col!=lastCol){
				result.push_back(array[row][col]);
				row--;
				col++;
				dir=false;
				continue;
			}
			if(row==0 && col!=lastCol){
				result.push_back(array[row][col]);
				col++;
				dir=true;
				continue;
			}
			if(row==0 && col==lastCol){
				result.push_back(array[row][col]);
				row++;
				dir=true;
				continue;
			}
			if(row!=0 && col==lastCol){
				result.push_back(array[row][col]);
				row++;
				dir=true;
				continue;
			}
		}
	}
	return result;
}


int main(){
	vector<vector<int>> array{{1,3,4,10},{2,5,9,11},{6,8,12,15},{7,13,14,16}};
	for(int i=0;i<array.size();i++){
		for(int j=0;j<array[i].size();j++){
			cout<<array[i][j]<<'\t';
		}
		cout<<endl;
	}

	vector<int> result = zigzagTraverse(array);
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<' ';
	}
	cout<<endl;
	return 0;
}
