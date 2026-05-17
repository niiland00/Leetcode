class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        
        int count = 1;      // 預設第一個數字算入序列中
        int prediff = 0;    // 一開始沒有前一個差值，設為 0
        
        // nums.size() 回傳的是無號整數 (size_t)，減 1 時要小心不要變成負數溢位
        // 因為前面已經過濾掉 size < 2 的情況，所以 nums.size() - 1 絕對安全
        for (size_t i = 0; i < nums.size() - 1; ++i) {
            int currdiff = nums[i + 1] - nums[i];
            
            if ((prediff <= 0 && currdiff > 0) || (prediff >= 0 && currdiff < 0)) {
                count++;
                prediff = currdiff;
            }
        }
        
        return count;
    }
};