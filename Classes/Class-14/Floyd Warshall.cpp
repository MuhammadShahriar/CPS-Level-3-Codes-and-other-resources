
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&dist){
	    int n = dist[0].size();

	    for ( int k = 0; k < n; k++ ) {
	        for ( int i = 0; i < n; i++ ) {
	            for ( int j = 0; j < n; j++ ) {
	                if ( dist[i][k] != -1 && dist[k][j] != -1 ) {
	                    if ( dist[i][j] == -1 ) {
	                        dist[i][j] = dist[i][k] + dist[k][j];
	                    }
	                    else if ( dist[i][k] + dist[k][j] < dist[i][j] ) {
	                        dist[i][j] = dist[i][k] + dist[k][j];
	                    }
	                }
	            }
	        }
	    }
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends
