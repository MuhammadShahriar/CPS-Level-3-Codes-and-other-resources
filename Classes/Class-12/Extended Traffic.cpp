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
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
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

const int mx = 223;
int dist[mx];

struct info {
    int u, v, w;
};
vector<info> edge;
bool isRelaxed[mx];
bool vis[mx];
int b[mx];
vi adj[mx];

void dfs ( int u )
{
    vis[u] = 1;

    for ( auto v : adj[u] ) {
        if (!vis[v] ) {
            dfs ( v );
        }
    }
}

void belmanFord ( int s, int n )
{
    for ( int i = 1; i <= n; i++ ) dist[i] = inf;
    dist[s] = 0;

    for ( int i = 1; i <= n; i++ ) {
        for ( auto  e : edge ) {
            int u = e.u;
            int v = e.v;
            int w = e.w;

            if ( dist[u] < inf ) {
                if ( dist[u] + w < dist[v] ) {
                    dist[v] = max ( -inf, dist[u] + w );
                    if ( i == n ) {
                        isRelaxed[v] = 1;
                    }
                }
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
	    edge.clear();
	    int n, m;
	    cin >> n;
	    for ( int i = 1; i <= n; i++ ) {
	        vis[i] = 0;
	        isRelaxed[i] = 0;
	        adj[i].clear();

	        cin >> b[i];
	    }

	    cin >> m;
	    for ( int i = 1; i <= m; i++ ) {
	        int u, v;
	        cin >> u >> v;
	        int d = b[v] - b[u];
	        int w = 1LL * d * d * d;
	        edge.PB ( {u, v, w} );
	    }

	    belmanFord(1, n);
	    for ( int i = 1; i <= n; i++ ) {
	        if ( isRelaxed[i] ) {
	            dfs (i);
	        }
	    }

	    int q;
	    cin >> q;

	    cout << "Case " << tc << ":\n";
	    while ( q-- ) {
	        int node;
	        cin >> node;

	        if ( dist[node] == inf || vis[node] || dist[node] < 3 ) {
	            cout << "?\n";
	        }
	        else cout << dist[node] << endl;
	    }


	}


	return 0;
}













