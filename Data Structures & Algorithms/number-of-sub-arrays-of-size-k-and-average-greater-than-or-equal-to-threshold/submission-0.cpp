class Solution {
   public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int cur_sum = 0;
        for (int i = 0; i < k; i++) cur_sum += arr[i];
        int ans = 0;
        if (cur_sum >= k * threshold) ans++;
        for (int i = k; i < n; i++) {
            cur_sum += arr[i];
            cur_sum -= arr[i - k];
            if (cur_sum >= k * threshold) ans++;
        }
        return ans;
    }
};