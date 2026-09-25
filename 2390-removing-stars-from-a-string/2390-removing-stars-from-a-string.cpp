class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        int i = 0;

        for(int j = 0; j < n; j++) {
            if(s[j] == '*'){
                i--;
            }else{
                s[i] = s[j];
                i++;
            }
        }
        s.resize(i);
        return s;
    }
};