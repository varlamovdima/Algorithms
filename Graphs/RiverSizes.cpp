#include <vector>
#include <iostream>
using namespace std;


vector<vector<int>> getUnvisitedNeighbors(int i, int j, vector<vector<int>> &matrix, 
vector<vector<bool>> &visited){
    vector<vector<int>> unvisitedNeighbors{};
    if(i>0 && !visited[i-1][j]){
        unvisitedNeighbors.push_back({i-1,j});
    }
    if(i<matrix.size()-1 && !visited[i+1][j]){
        unvisitedNeighbors.push_back({i+1,j});
    }
    if(j>0 && !visited[i][j-1]){
        unvisitedNeighbors.push_back({i,j-1});
    }
    if(j<matrix[0].size()-1 && !visited[i][j+1]){
        unvisitedNeighbors.push_back({i,j+1});
    }
    return unvisitedNeighbors;
}

void traverseNode(int i, int j, vector<vector<int>> &matrix,
vector<vector<bool>> &visited, vector<int> &sizes){
    int currentRiverSize = 0;
    vector<vector<int>> nodesToExplore{{i,j}};
    
    while (nodesToExplore.size()!=0){
        vector<int> currentNode = nodesToExplore.back();
        nodesToExplore.pop_back();
        i = currentNode[0];
        j = currentNode[1];
        if(visited[i][j]==true){
            continue;
        }
        visited[i][j] = true;
        if(matrix[i][j]==0){
            continue;
        }
        currentRiverSize++;
        vector<vector<int>> unvisitedNeighbors = getUnvisitedNeighbors(i,j,matrix,visited);
        for(int i=0;i<unvisitedNeighbors.size();i++){
            nodesToExplore.push_back(unvisitedNeighbors[i]);
        }
    } 
    if(currentRiverSize>0){
        sizes.push_back(currentRiverSize);
    }
}

vector<int> riverSizes(vector<vector<int>> matrix) {
    vector<int> sizes = {};
    vector<vector<bool>> visited(matrix.size(),vector<bool>(matrix[0].size(),false));
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            if(visited[i][j]==true){
                continue; 
            }else{
                traverseNode(i,j,matrix,visited,sizes);
            }
        }
    }
    return sizes;
}

int main(){
    vector<vector<int>> matrix{
        {1,0,0,1,0},
        {1,0,1,0,0},
        {0,0,1,0,1},
        {1,0,1,0,1},
        {1,0,1,1,0}
    };
    vector<int> result = riverSizes(matrix);
    for(int i=0;i<result.size();i++){
        cout<< result[i] << ' ';
    }
    return 0;
}