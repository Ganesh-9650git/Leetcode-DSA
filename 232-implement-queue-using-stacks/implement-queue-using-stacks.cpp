#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {
        // Constructor remains empty
    }
    
    // Push element x to the back of the queue
    void push(int x) {
        s1.push(x);
    }
    
    // Removes the element from the front of the queue and returns it
    int pop() {
        // Ensure s2 has the current elements in reversed order
        shiftStacks(); 
        int result = s2.top();
        s2.pop();
        return result;
    }
    
    // Get the front element
    int peek() {
        shiftStacks();
        return s2.top();
    }
    
    // Returns whether the queue is empty
    bool empty() {
        return s1.empty() && s2.empty();
    }

private:
    // Helper function to move elements from s1 to s2 when s2 is empty
    void shiftStacks() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
};
