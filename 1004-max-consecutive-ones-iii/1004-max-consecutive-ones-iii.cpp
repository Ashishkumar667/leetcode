class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, zeros = 0, maxLength = 0;

        while(r < nums.size()){
           if(nums[r] == 0){
            zeros++;
           } 

         if( zeros > k){
            if(nums[l] == 0)zeros--;
            l++;
           }

           if(zeros <= k){
            int length = r - l + 1;
             maxLength = max(length, maxLength);
           }

           r++;
        }
        return maxLength;
    }
};