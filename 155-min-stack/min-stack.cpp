class MinStack {
public:
long long min;
stack<long long> st;
    MinStack() {
        
    }
    
    void push(int val) {
        long long value=val;
        if(st.empty()){
            st.push(value);
            min=value;
        }
        else{
            if(value>=min){
                st.push(value);
            }
            else{
                st.push(2*value-min);
                min=value;
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        long long x=st.top();
        st.pop();
        if(x<min){
            min=2*min-x;
        }
    }
    
    int top() {
         if(st.empty()) return -1;
        long long x=st.top();
        if (x < min) return min; else return x;
    }
    
    int getMin() {
        return min;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */