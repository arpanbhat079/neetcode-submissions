class Solution {
   public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> freq;
        int n = nums.size();
        for (int i = 0; i < min(k + 1, n); i++) freq[nums[i]]++;
        for (auto [x, y] : freq) {
            if (y > 1) {
                return true;
            }
        }
        for (int i = min(k + 1, n); i < n; i++) {
            freq[nums[i - min(k + 1, n)]]--;
            freq[nums[i]]++;
            if (freq[nums[i]] > 1) return true;
        }
        return false;
    }
};