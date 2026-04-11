class Solution {
public:
    
    int findKthLargest(vector<int>& nums, int k) {
        //將第k大轉換成目標index
        int target_index=nums.size()-k;
        return quickselect(nums, 0, nums.size()-1, target_index);
    }

private:

    int quickselect(vector<int>& nums, int left, int right, int target_index){
        if (left == right) {
            return nums[left];
        }

        int pivot_index=left+rand()%(right-left+1);
        //基準點換到最右才不影響照順序比較
        swap(nums[pivot_index],nums[right]);
        //定一個讓比較小的值去的地方
        int pivot=nums[right];
        int p=left;
        for(int i=left;i<right;i++){
            //如果比較大就不會執行if，for繼續檢查下個數字
            if(nums[i]<pivot){
                swap(nums[i],nums[p]);
                p++;
            }
        }
        swap(nums[p],nums[right]);

        if(p==target_index){
            return nums[p];
        } 
        else if(p<target_index){
            //index是絕對位置，所以剪枝不影響
            return quickselect(nums, p+1, right, target_index);
        }
        else{
            return quickselect(nums, left, p-1, target_index);
        }
    }
};