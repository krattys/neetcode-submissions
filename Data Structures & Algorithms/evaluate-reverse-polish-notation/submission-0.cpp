class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string token: tokens) {
            if (token == "+") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int tmp = num1 + num2;
                st.push(tmp);
            } else if (token == "*") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int tmp = num1 * num2;
                st.push(tmp);
            } else if (token == "-") {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                int tmp = num1 - num2;
                st.push(tmp);
            } else if (token == "/") {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                int tmp = num1 / num2;
                st.push(tmp);
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
