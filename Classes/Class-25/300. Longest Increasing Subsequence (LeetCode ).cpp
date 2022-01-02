class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int inf = 1e5;
        int n = nums.size();
        vector<int> d ( n+1, inf );
        d[0] = -inf;
        
        for ( int i = 0; i < n; i++ ) {
            int j = upper_bound ( d.begin(), d.end(), nums[i] ) - d.begin();
            if ( d[j-1] < nums[i] ) {
                d[j] = nums[i];
            }
        }
        
        int ans = 0;
        for ( int i = 1; i <= n; i++ ) {
            if ( d[i] != inf ) {
                ans = i;
            }
        }
        
        return ans;
    }
};