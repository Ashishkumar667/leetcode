class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>st;

        for(int i = 0; i < asteroids.size(); i++){
            while(!st.empty() && asteroids[i]<0 && st.back() > 0 ){
                int sum = asteroids[i]  + st.back();
                if(sum < 0){
                    st.pop_back();
                }
                if(sum>0){
                    asteroids[i] = 0;
                }else if(sum == 0){
                    st.pop_back();
                    asteroids[i] = 0;
                }
            }
            if(asteroids[i] != 0){
                st.push_back(asteroids[i]);
            }
        }
        return st;
    }
};