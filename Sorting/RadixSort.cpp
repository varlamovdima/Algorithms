// [ 123, 326, 1, 4545, 32, 2, 54]

#include <iostream>
#include <vector>
#include <cmath>
#include <math.h>
using namespace std;

int maxValue(vector<int> array){
    int max = -1*INFINITY;
    for(int i=0;i<array.size()-1;i++){
        if(array[i]>max)
            max = array[i];
    }
    return max;
}

int numDigit(int maxValue){
    int count = 1;
    int value = maxValue;
    while(floor(value)!=0){
        value = floor(value/10);
        if(value>0){
            count++;
        }
    }
    return count;
}

// 1,32,33,123,54,4545,326
// 0,3,3,2,5,4,2
// [1,0,2,2,1,1,0,0,0,0]
// [1,1,1,3,5,6,7,7,7,7]
// [1,123,326,32,33,4545,54]
vector<int> countSort(vector<int> array, int digit){
    
    vector<int> sorted(array.size(),0);
    vector<int> count(10,0);

    for(int i=0;i<array.size();i++){
        int value = array[i]%(int)pow(10,digit+1);
        value = (int)(value/(int)pow(10,digit));
        count[value]++;
    }
   
    for(int i=1;i<count.size();i++){
        count[i] = count[i-1]+count[i];
    }
    cout<<endl;
    for(int i=array.size()-1;i>=0;i--){
        int value = array[i]%(int)pow(10,digit+1);
        value = (int)(value/(int)pow(10,digit));
        int newIdx = count[value]-1;
        count[value]--; // 5
        sorted[newIdx] = array[i];
      
    }
    return sorted;

}

vector<int> radixSort(vector<int> array) {
    if(array.size()==0)
        return array;

    int digit = 0;
    int max = maxValue(array);
    while(digit<numDigit(max)){
        array = countSort(array,digit);
        for(int i =0;i<array.size();i++){
            cout<<array[i]<< ' ';
        }
        cout<<endl;
        digit++;
    }


    return array;
}

int main(){
    vector<int> array = {123, 326, 1, 4545, 32, 2, 54};
    vector<int> result = radixSort(array);
    // for(int i =0;i<result.size();i++){
    //     cout<<result[i]<< ' ';
    // }
    return 0;
}

