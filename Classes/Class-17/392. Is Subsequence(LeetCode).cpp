
int dp[123][10123];
int n, m;
string s1, s2;


int LCS ( int i, int j )
{
    if ( i >= n || j >= m ) return 0;
    if ( dp[i][j] != -1 ) return dp[i][j];

    int ret;

    if ( s1[i] == s2[j] ) ret = 1 + LCS ( i+1, j+1 );
    else {
        ret = max ( LCS ( i+1, j ), LCS ( i, j+1 ) );
    }

    return dp[i][j] = ret;
}


class Solution {
public:
    bool isSubsequence(string s, string t) {
        s1 = s;
        s2 = t;

        n = s1.size();
        m = s2.size();

        memset ( dp, -1, sizeof(dp) );
        int lcs = LCS ( 0, 0 );
        if ( lcs == n ) return true;
        return false;
    }
};
