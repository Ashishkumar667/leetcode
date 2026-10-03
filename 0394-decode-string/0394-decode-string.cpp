class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;

        string current = "";
        int num = 0;

        for (char ch : s) {

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            else if (ch == '[') {
                numStack.push(num);
                strStack.push(current);

                num = 0;
                current = "";
            }

            else if (ch == ']') {
                int repeat = numStack.top();
                numStack.pop();

                string previous = strStack.top();
                strStack.pop();

                string temp = "";

                for (int i = 0; i < repeat; i++) {
                    temp += current;
                }

                current = previous + temp;
            }

            else {
                current += ch;
            }
        }

        return current;
    }
};