class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        stack<int>st;
        long long number = 0;
        int result = 0;
        int sign = 1;

        for(int i = 0; i<n; i++){
            if(isdigit(s[i])){
                number = (number*10) + (s[i] - '0');
            }else if(s[i] == '+'){
                result += (number*sign);
                number = 0;
                sign = 1;
            }else if(s[i] == '-'){
                result += (number*sign);
                number = 0;
                sign = -1;
            }else if(s[i] == '('){
                st.push(result);
                st.push(sign);
                number = 0;
                result = 0;
                sign = 1;
            }else if(s[i] == ')'){
                result += (number*sign);
                number = 0;
                int storedSign = st.top();
                st.pop();
                int storedResult = st.top();
                st.pop();

                result = (result*storedSign);
                result += storedResult;
            }
        }
        result += (number*sign);
        return result;
    }
};