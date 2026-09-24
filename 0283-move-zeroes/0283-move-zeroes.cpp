class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;

        for (int m = 0; m < nums.size(); m++) {

            if (nums[m] != 0) {

                if (nums[i] == 0) {
                    int temp = nums[i];
                    nums[i] = nums[m];
                    nums[m] = temp;
                }

                i++;
            }
        }
    }
};