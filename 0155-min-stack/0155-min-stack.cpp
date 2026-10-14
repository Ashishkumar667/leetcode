class MinStack {
private:
    stack<long long> st;
    long long mini = LLONG_MAX;

public:
    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        }
        else if (val >= mini) {
            st.push(val);
        }
        else {
            st.push(2LL * val - mini);
            mini = val;
        }
    }

    void pop() {
        if (st.empty()) {
            return;
        }

        long long n = st.top();
        st.pop();

        if (n < mini) {
            mini = 2LL * mini - n;
        }

        if (st.empty()) {
            mini = LLONG_MAX;
        }
    }

    int top() {
        if (st.empty()) {
            return -1;
        }

        long long x = st.top();

        if (x < mini) {
            return static_cast<int>(mini);
        }

        return static_cast<int>(x);
    }

    int getMin() {
        if (st.empty()) {
            return -1;
        }

        return static_cast<int>(mini);
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