#include<bits/stdc++.h>

class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        int k = q1.front();
        q1.pop(); //q1 queue got empty;
        swap(q1, q2); // swapping elements from q2 to q1 to get remaining elements
        return k;
                                
    }
    
    int top() {
        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }
        int k = q1.front();
        q1.pop();
        swap(q1, q2);
        q1.push(k);  // restoring original queue
        return k;
    }
    
    bool empty() {
        if(q1.size()){
            return false;
        } else {
            return true;
        }
        //return(q1.empty() && q2.empty()); also we can do this.
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */