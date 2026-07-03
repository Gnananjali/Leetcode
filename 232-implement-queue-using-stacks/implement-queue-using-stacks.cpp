class MyQueue {
public:
    stack<int> st,newSt;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
        
    }
    
    int pop() {
        if(newSt.empty()){
        while(!st.empty()){
        int x = st.top();
        newSt.push(x);
        st.pop();

        }

        }
        int x = newSt.top();
        newSt.pop();
        return x;
    }
    
    int peek() {
        if(newSt.empty()){
            while(!st.empty()){
                newSt.push(st.top());
                st.pop();
            }
        }
        return newSt.top();
    }
    
    bool empty() {
    return newSt.empty()&&st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */