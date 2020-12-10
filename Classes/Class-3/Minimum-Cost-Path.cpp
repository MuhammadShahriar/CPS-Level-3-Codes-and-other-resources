// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int shortest(vector<vector<int> > &grid ,int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int> > grid(n);

        for (int i = 0; i < n; i++)
        {
            grid[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }

        cout << shortest(grid,n) << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// grid : given n*n grid
// n : size of the square grid

int dx[] = { 0, 0, +1, -1, -1  +1, -1, +1 };
int dy[] = { +1, -1, 0, 0, -1, +1, +1, -1 };

int shortest(vector<vector<int> > &grid, int n)
{
    long long dist[n][n];
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            dist[i][j] = 1e18;
        }
    }

    priority_queue< pair<long long, pair<int, int> >, vector<pair<long long, pair<int, int> >>, greater<pair<long long, pair<int, int> >> > pq;

    dist[0][0] = grid[0][0];
    pq.push ( { grid[0][0], {0, 0} } );

    while ( !pq.empty() ) {
        pair<int, int> u = pq.top().second;
        long long curD = pq.top().first;
        pq.pop();

        int x = u.first;
        int y = u.second;

        if ( dist[x][y] < curD ) continue;

        for ( int i = 0; i < 4; i++ ) {
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if ( x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && curD + grid[x1][y1] < dist[x1][y1] ) {
                dist[x1][y1] = curD + grid[x1][y1];
                pq.push ( { dist[x1][y1], { x1, y1 } } );
            }

        }

    }

    return dist[n-1][n-1];

}















