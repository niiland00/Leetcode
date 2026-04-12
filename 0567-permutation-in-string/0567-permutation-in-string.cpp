class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();

        if(n1>n2) return false;
        
        vector<int> s1_count(26,0);
        vector<int> window_count(26,0);
        for(int i=0;i<n1;i++){
            //扣掉字母的ASCII，使排進正確的26字母陣列位置
            s1_count[s1[i]-'a']++;
            window_count[s2[i]-'a']++;
        }

        //避免忽略第一個視窗就出現答案
        if(s1_count==window_count) return true;
        for(int i=n1;i<n2;i++){
                //算進右邊字元的頻率，扣掉左邊字元的頻率
                window_count[s2[i]-'a']++;
                window_count[s2[i-n1]-'a']--;

                if(s1_count==window_count) return true;
        }
            
        return false;
    }
};