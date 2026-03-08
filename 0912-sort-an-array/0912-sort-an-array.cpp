class Solution {
public:
    
    void merge(vector<int>& nums, int left, int mid, int right){
        int n1=mid-left+1;
        int n2=right-(mid+1)+1;

        vector<int> L(n1), R(n2);
        for(int i=0; i<n1; i++) L[i] = nums[left+i];
        for(int j=0; j<n2; j++) R[j] = nums[mid+1+j];

        int i=0, j=0, k=left; 
        //處理右半邊陣列時，起始點k就不一定是0
        //不能用for固定k初始值
        while(i<n1 && j<n2){
            if(L[i]<R[j]) nums[k++]=L[i++];
            else nums[k++]=R[j++];
        }

        //每一層已確定是排好的陣列
        while(i<n1) nums[k++]=L[i++];
        while(j<n2) nums[k++]=R[j++];

    }
    void mergesort(vector<int>& nums, int left, int right){
        if(left >= right) return;
        int mid = (right-left)/2 + left;
        mergesort(nums, left, mid);
        mergesort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }
    vector<int> sortArray(vector<int>& nums) {
       mergesort(nums, 0, nums.size()-1);
       return nums; 
    }
};
