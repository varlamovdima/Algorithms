#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str){
        int leftPtr = 0;
        int rightPtr = str.size()-1;
        while(leftPtr<=rightPtr){
                if(str[leftPtr]==str[rightPtr]){
                        leftPtr++;
                        rightPtr--;
                }else{
                        return false;
                }
        }
        return true;
}

int main(){
	string str = "abcdcba";
	cout<<isPalindrome(str)<<endl;
	return 0;
}
