class MinStack {
public:
    stack<pair<int, int>> st;
    MinStack() {
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
            return;
        }
        st.push({val, min(getMin(), val)});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
