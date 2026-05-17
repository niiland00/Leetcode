class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        
        // 不偷最後一家
        int planA = robLinear(nums, 0, n - 2);
        // 不偷第一家
        int planB = robLinear(nums, 1, n - 1);
        
        return max(planA, planB);
    }

private:
    int robLinear(const vector<int>& nums, int start, int end) {
        int prev2 = 0; 
        int prev1 = 0; 
        
        for (int i = start; i <= end; ++i) {
            // 當前最大值 = max(不偷這家, 偷這家 + 前前一家的最大值)
            int curr = max(prev1, prev2 + nums[i]);
            
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};