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

const int mx = 2512;

struct info {
    int u, v, w;
};

vector<info> e;
ll dist[mx];
int par[mx];


vi bellmanFord ( int s, int n, int m )
{
    vi path;

    for ( int i = 1; i <= n; i++ ) dist[i] = infLL;
    dist[s] = 0;

    int x = -1;
    for ( int i = 1; i <= n; i++ ) {
        x = -1;
        for ( int j = 0; j < m; j++ ) {
            int u = e[j].u;
            int v = e[j].v;
            int w = e[j].w;

            if ( dist[u] + w < dist[v] ) {
                dist[v] = dist[u] + w;
                par[v] = u;
                x = v;
            }
        }
    }

    if ( x == -1 ) return path;

    for ( int i = 1; i <= n; i++ ) {
        x = par[x];
    }


    int y = x;

    while ( y != x || sz (path) == 0 ) {
        path.PB ( y );
        y = par[y];
    }

    path.PB ( x );
    reverse ( all ( path ) );

    return path;


}

int main()
{
	optimize();

	int n, m;
	cin >> n >> m;
	for ( int i = 1; i <= m; i++ ) {
	    int u, v, w;
	    cin >> u >> v >> w;
	    e.PB ( {u, v, w } );
	}

	vi ans = bellmanFord ( 1, n, m );

	if ( sz ( ans ) == 0 ) cout << "NO\n";
	else {
	    cout << "YES\n";
	    for ( auto u : ans ) cout << u << " ";
	    cout << endl;
	}


	return 0;
}













