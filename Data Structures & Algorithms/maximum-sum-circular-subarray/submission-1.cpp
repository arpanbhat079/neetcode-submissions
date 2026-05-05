class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // sum is either maxsub array sum or tot sum - min array sum
        int tot = accumulate(nums.begin(),nums.end(),0);
        int ma = *max_element(nums.begin(),nums.end());
        if(ma<0) return ma;
        int ma_sum = -1e9;
        int mi_sum = 1e9;
        int cur_sum1 = 0;
        int cur_sum2 = 0;
        for(auto x:nums){
            // max
            cur_sum1 = max(x,cur_sum1+x);
            ma_sum = max(ma_sum,cur_sum1);
            // min 
            cur_sum2 = min(x,cur_sum2+x);
            mi_sum = min(mi_sum,cur_sum2);
        }
        return max(ma_sum,tot-mi_sum);
    }
};