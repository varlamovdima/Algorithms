#include <vector>
#include <unordered_map>
using namespace std;

// Feel free to add new properties and methods to the class.
class MinMaxStack {
public:
        vector<unordered_map<string,int>> minMaxStack = {};
        vector<int> stack = {};

        int peek() {
                return stack[stack.size()-1];
        }

        int pop() {
                int value = stack[stack.size()-1];
                stack.pop_back();
                minMaxStack.pop_back();
                return value;
        }

        void push(int number) {
                unordered_map<string,int>  newMinMax = {{"min",number},
          {"max",number}};
                if(minMaxStack.size()!=0){
                        unordered_map<string,int> lastMinMax = minMaxStack[minMaxStack.size()-1];
                        newMinMax["min"] = min(lastMinMax["min"],number);
                        newMinMax["max"] = max(lastMinMax["max"],number);
                }
                minMaxStack.push_back(newMinMax);
                stack.push_back(number);
        }

        int getMin() {
                return minMaxStack[minMaxStack.size()-1]["min"];
        }

        int getMax() {
                return minMaxStack[minMaxStack.size()-1]["max"];
        }
}
