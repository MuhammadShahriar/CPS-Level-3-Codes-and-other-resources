///   ***   ---   |||		 In the name of ALLAH		|||   ---   ***   ///



#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2e9;
const ll infLL = 1e18;
#define MOD 1000000007

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
//
//debug
template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu(){cerr << endl;}
template<typename T>void faltu(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void faltu(T arg,const hello&...rest){cerr<<arg<<' ';faltu(rest...);}
//#else
//#define dbg(args...)

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }


int dx[] = { 0, 0, +1, -1, -1  +1, -1, +1 };
int dy[] = { +1, -1, 0, 0, -1, +1, +1, -1 };


const int mx = 1e4+123;
vector<vi> adj[mx];
ll dist[12][mx];

void dijkstra ( int s, int n, int d )
{
    for ( int i = 0; i <= d; i++ ) {
        for ( int j = 0; j < n; j++ ) {
            dist[i][j] = infLL;
        }
    }

    priority_queue<vl, vector<vl>, greater<vl>> pq;

    dist[0][s] = 0;
    pq.push ( { 0, 0, s } );

    while ( !pq.empty() ) {
        ll curD = pq.top()[0];
        int cnt = pq.top()[1];
        int u = pq.top()[2];
        pq.pop();

        if ( dist[cnt][u] < curD ) continue;

        for ( auto e : adj[u] ) {
            int v = e[0];
            ll w = e[1];
            int typ = e[2];

            if ( cnt + typ <= d && dist[cnt][u] + w < dist[cnt+typ][v] ) {
                dist[cnt+typ][v] = dist[cnt][u] + w;
                pq.push ( { dist[cnt+typ][v], cnt+typ, v } );
            }
        }
    }

}

int main()
{
	optimize();

	int T;
	cin >> T;
	for ( int tc = 1; tc <= T; tc++ ) {
	    int n, m, k, d;
	    cin >> n >> m >> k >> d;
	    for ( int i = 0; i < n; i++ ) adj[i].clear();

	    for ( int i = 0; i < m; i++ ) {
	        int u, v, w;
	        cin >> u >> v >> w;
	        adj[u].PB ( { v, w, 0 } );
	    }


	    for ( int i = 0; i < k; i++ ) {
	        int u, v, w;
	        cin >> u >> v >> w;
	        adj[u].PB ( { v, w, 1 } );
	    }

	    dijkstra ( 0, n, d );

	    ll ans = infLL;
	    for ( int i = 0; i <= d; i++ ) {
	        ans = min ( ans, dist[i][n-1] );
	    }

	    if ( ans == infLL ) cout << "Case " << tc << ": Impossible\n";
	    else cout << "Case " << tc << ": " << ans << endl;
	}


	return 0;
}













