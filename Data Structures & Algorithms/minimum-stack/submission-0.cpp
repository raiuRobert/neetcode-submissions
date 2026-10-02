class MinStack {
private:
    stack<int> st;        // the real values
    stack<int> minSt;     // minSt.top() = minimum of everything in st

public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        if (minSt.empty()) {
            minSt.push(val);                       // first element: it is the min
        } else {
            minSt.push(min(val, minSt.top()));     // new min = smaller of val and old min
        }
    }

    void pop() {
        st.pop();
        minSt.pop();      // keep both stacks the same height
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};