#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(vector<vector<int>> , int ,int );

int printSolution(vector <int> dist, int n)
{

   for (int i = 0; i < n; i++)
      printf("%d ", dist[i]);

}
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;

        vector<vector<int>> g(V);

        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }

        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }

        int s;
        cin>>s;

        vector <int> res = dijkstra(g, s, V);
        printSolution (res, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
vector <int> dijkstra(vector<vector<int>> adj, int s, int n)
{
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            if ( adj[i][j] == 0 ) adj[i][j] = 1e7;
        }
    }

    vector<int> dist(n, 1e7);
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    dist[s] = 0;
    pq.push( { 0, s } );

    while ( !pq.empty() ) {
        int u = pq.top().second;
        int curD = pq.top().first;
        pq.pop();

        if ( dist[u] < curD ) continue;

        for ( int v = 0; v < n; v++ ) {
            if ( curD + adj[u][v] < dist[v] ) {
                dist[v] = curD + adj[u][v];
                pq.push( { dist[v], v } );
            }
        }

    }

    return dist;

}



















