const int mx = 1e3+123;
int dp[mx][mx], n, m;
string s, t;

int solve ( int i, int j )
{
    if ( i >= n || j >= m ) return 0;
    if ( dp[i][j] != -1 ) return dp[i][j];
    
    int ret = 0;
    if ( s[i] == t[j] ) ret = s[i] + solve ( i+1, j+1 );
    else {
        ret = max ( solve ( i+1, j ), solve ( i, j+1 ) );
    }
    
    return dp[i][j] = ret;    
}


class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        s = s1;
        t = s2;
        
        n = s.size();
        m = t.size();
        
        memset ( dp, -1, sizeof(dp) );
        
        int sumA = solve ( 0, 0 );
        
        int allSumA = 0;
        
        for ( auto u : s ) allSumA += u;
        for ( auto u : t ) allSumA += u;
        
        int ans = allSumA - ( 2 * sumA );
        return ans;
    }
};