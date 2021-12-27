class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int inf = 1e5;
        int n = nums.size();
        vector<int> d ( n+1, inf );
        d[0] = -inf;
        
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 1; j <= n; j++ ) {
                if ( d[j-1] < nums[i] && nums[i] < d[j] ) {
                    d[j] = nums[i];
                }
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