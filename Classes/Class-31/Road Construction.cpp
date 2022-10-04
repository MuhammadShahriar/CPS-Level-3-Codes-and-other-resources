
///   ***   ---   ||         In the name of ALLAH        |||   ---   ***   ///



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

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {            cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }

int par[60];
int sz[60];

int find_par ( int u ) {
    if ( u == par[u] ) return u;
    return par[u] = find_par ( par[u] );
}

void Union ( int u, int v ) {
    if ( sz[u] < sz[v] ) swap ( u, v );
    par[v] = u;
    sz[u] += sz[v];
}

int main()
{
    optimize();

    int T;
    cin >> T;

    for ( int tc = 1; tc <= T; tc++ ) {
        int m;
        cin >> m;

        vector<pair<int, pair<string, string>>> tmpEdges;
        set<string> st;

        while ( m-- ) {
            string u, v;
            int w;

            cin >> u >> v >> w;
            tmpEdges.push_back({w, {u, v}});

            st.insert(u);
            st.insert(v);
        }

        int n = st.size();

        map<string, int> id;

        int cnt = 1;

        for ( auto u : st ) {
            id[u] = cnt;
            cnt++;
        }

        vector<pair<int, pair<int, int>>> edges;

        for ( auto e : tmpEdges ) {
            string u = e.second.first;
            string v = e.second.second;
            int w = e.first;

            edges.push_back( { w, { id[u], id[v] } } );
        }

        for ( int i = 1; i <= n; i++ ) {
            sz[i] = 0;
            par[i] = i;
        }

        sort ( edges.begin(), edges.end() );

        int cost = 0;
        cnt = 0;

        for ( auto e : edges ) {
            int u = e.second.first;
            int v = e.second.second;
            int w = e.first;

            u = find_par(u);
            v = find_par(v);

            if ( u != v ) {
                Union(u, v);
                cost += w;
                cnt++;
                if ( cnt == n-1 ) break;
            }
        }

        if ( cnt == n-1 ) cout << "Case " << tc << ": " << cost << endl;
        else cout << "Case " << tc << ": " << "Impossible" << endl;

    }

    return 0;
}














