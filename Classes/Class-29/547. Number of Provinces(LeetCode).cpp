class Solution {
public:
    
    vector<int> par;
    vector<int> sz;
    
    int find_par ( int u ) {
        if ( u == par[u] ) return u;
        return par[u] = find_par ( par[u] );
    }
    
    void Union ( int u, int v ) {
        if ( sz[u] < sz[v] ) swap ( u, v );
        par[v] = u;
        sz[u] += sz[v];
    }
    
    int findCircleNum(vector<vector<int>>& g) {
        int n = g.size();
        for ( int i = 0; i < n; i++ ) par.push_back ( i );
        sz.resize( n, 1 );
        
        for ( int i = 0; i < n; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                if ( g[i][j] ) {
                    int u = find_par ( i );
                    int v = find_par ( j );
                    
                    if ( u != v ) {
                        Union ( u, v );
                    }
                }
            }
        }
        
        int ans = 0;
        for ( int i = 0; i < n; i++ ) if ( par[i] == i ) ans++;
        return ans;
    }
};