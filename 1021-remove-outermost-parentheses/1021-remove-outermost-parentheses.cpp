class Solution {
public:
    string removeOuterParentheses(string s) {
        string answer = "";
        int depth = 0;
        int n = s.length();

        for (int i=0; i<n; i++){
            if(s[i] == '('){
                if(depth > 0){
                    answer += s[i];
                }
                depth++;
            }else{
                depth--;
                if(depth>0){
                    answer += s[i];
                }
            }
        }
        return answer;
    }
};