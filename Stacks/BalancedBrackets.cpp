// Write a fucntion that takes in string made up of brackers
// and other optional characters. The fucntion should return 
// a boolean representing whether the string is balanced with 
// regards to brackets.

// A string is said to be balanced if it has se many openining brackets of 
// a certain type as it has closing brackets of that type and 
// if no brackets is unmatched. Note that an opening bracker can't match
// a corresponding closing bracket that comes bafore it, and similarly, a closing
// bracket can't match a corresponding opening bracket that comes after it.
// Also, brackets can't overlap each other as in [(])
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

bool balancedBrackets(string str){
    string openingBracket = "([{";
    string closingBracket = ")]}";
    unordered_map<char,char> matchingBrackets = {
        {')','('},
        {']','['},
        {'}','{'}
    };
    stack<char> stack;
    for(char character : str){
        if(openingBracket.find(character)!=string::npos){
            stack.push(character);
        }
        else if(closingBracket.find(character)!=string::npos){
            if(stack.size()==0)
                return false;
            
            if(stack.top()==matchingBrackets[character])
                stack.pop();
            else
                return false;
        }
    }
    return stack.size()==0;
}

int main(){
    string str = "([])(){}(())()()";
    cout<<balancedBrackets(str)<<'\n';

    return 0;
}