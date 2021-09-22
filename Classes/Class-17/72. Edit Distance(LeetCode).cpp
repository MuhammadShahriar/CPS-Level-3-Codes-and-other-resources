
const int mx = 512;
int dp[mx][mx];
int n, m;
string s1, s2;

int solve ( int i, int j )
{
    if ( i >= n ) return m - j;
    if ( j >= m ) return n - i;
    if ( dp[i][j] != -1 ) return dp[i][j];

    int ret;

    if ( s1[i] == s2[j] ) ret = solve ( i+1, j+1 );
    else {
        int ret1 = 1 + solve ( i+1, j+1 ); // Replace
        int ret2 = 1 + solve ( i, j+1 ); // Insert
        int ret3 = 1 + solve ( i+1, j ); // Delete

        ret = min ( { ret1, ret2, ret3 } );
    }

    return dp[i][j] = ret;
}


class Solution {
public:
    int minDistance(string word1, string word2) {
        s1 = word1;
        s2 = word2;

        n = s1.size();
        m = s2.size();

        memset ( dp, -1, sizeof(dp) );
        return solve ( 0, 0 );

    }
};
