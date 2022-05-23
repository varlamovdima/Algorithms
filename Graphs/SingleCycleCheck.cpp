#include <iostream>
#include <vector>
using namespace std;


int getNextIdx(int currentIdx, vector<int> array){
    int jump = array[currentIdx];
    int nextIdx = (currentIdx + jump) % (int)array.size();
    return nextIdx>=0? nextIdx : nextIdx+array.size();
}

bool hasSingleCycle(vector<int> array) {
    int numElementsVisited = 0;
    int currentIdx = 0;
    while(numElementsVisited<array.size()){
        if(numElementsVisited>0 && currentIdx==0)
            return false;
        numElementsVisited++;
        currentIdx = getNextIdx(currentIdx,array);
    }
    return currentIdx == 0;  
}

int main(){
    vector<int> array{2,3,1,-4,-4,2};
    cout<<hasSingleCycle(array)<<endl;;
    return 0;
}