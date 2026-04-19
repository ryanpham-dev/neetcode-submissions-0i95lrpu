class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int total = 0;
        for (const auto& op : operations) {
            switch (op) {
                case '+': {
                    auto a = st.top();
                    st.pop();
                    auto b = st.top();
                    st.pop();
                    auto c = a + b;
                    total += c;
                    st.push(b);
                    st.push(a);
                    st.push(c);
                    break;
                }
                case 'C': {
                    auto a = st.top();
                    st.pop();
                    total -= a;
                    break;
                }
                case 'D': {
                    auto a = st.top();
                    st.pop();
                    auto b = a * 2;
                    total += b;
                    st.push(a);
                    st.push(b);
                    break;
                }
                default: {
                    int c = std::stoi(op);
                    total += c;
                    break;
                }
            }
        }
        return total;
    }
};