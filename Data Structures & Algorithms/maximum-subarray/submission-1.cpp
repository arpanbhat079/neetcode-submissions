class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ma_sum = -1e9;
        int cur_sum = 0;
        for(auto x:nums){
            cur_sum=max(x,cur_sum+x);
            ma_sum=max(ma_sum,cur_sum);
        }
        return ma_sum;
    }
};
