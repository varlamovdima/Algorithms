#include <iostream>
using namespace std;

int getNthFib(int n) {
    if(n==2)
        return 1;
    if(n==1)
        return 0;
  return getNthFib(n-1) + getNthFib(n-2);
}
// 0 1 1 2 3 5 8 13
int main(){
    int result = getNthFib(7);
    cout<<result<<endl;
    return 0;
}