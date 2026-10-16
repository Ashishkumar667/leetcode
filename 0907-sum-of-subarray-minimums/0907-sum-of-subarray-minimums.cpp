class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        stack<int> st;
        long long ans = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() &&
                   (i == n || arr[st.top()] >= arr[i])) {

                int mid = st.top();
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int right = i;

                long long leftCount = mid - left;
                long long rightCount = right - mid;

                long long contribution =
                    (1LL * arr[mid] * leftCount % MOD)
                    * rightCount % MOD;

                ans = (ans + contribution) % MOD;
            }

            if (i < n) {
                st.push(i);
            }
        }

        return ans;
    }
};