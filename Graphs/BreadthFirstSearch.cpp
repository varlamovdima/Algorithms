#include <vector>
using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
    string name;
    vector<Node *> children;

    Node(string str) { name = str; }

    vector<string> breadthFirstSearch(vector<string> *array) {
        deque<Node *> queue{this};
        while(!queue.empty()){
            Node current = *queue.front();
						queue.pop_front();
            array->push_back(current.name);
            for(int i=0;i<current.children.size();i++){
                queue.push_back(current.children[i]);
            }
        }
        return *array;
  }

    Node *addChild(string name) {
        Node *child = new Node(name);
        children.push_back(child);
        return this;
    }
};