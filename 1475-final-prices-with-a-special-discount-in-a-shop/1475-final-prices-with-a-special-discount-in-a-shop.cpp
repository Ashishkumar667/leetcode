class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        int n = prices.size();

        for(int j = 0; j < n; j++){
            while(!st.empty() && prices[j] <= prices[st.top()]){
                int discountIdx = st.top();
                st.pop();
                prices[discountIdx] -= prices[j];

            }
            st.push(j);
        }

        return prices;
    }
};