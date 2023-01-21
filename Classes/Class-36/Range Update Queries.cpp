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
 
const int mx = 2e5+123;
ll prop[mx*3];
bool vis[mx*3];
int a[mx];
 
void shift ( int id )
{
    prop[id*2] += prop[id];
    prop[id*2+1] += prop[id];
 
    vis[id*2] = vis[id*2+1] = 1;
    prop[id] = vis[id] = 0;
}
 
void init ( int id, int b, int e )
{
    if ( b == e ) {
        prop[id] = a[b];
        return;
    }
 
    int mid = ( b + e ) >> 1;
    init ( id*2, b, mid );
    init ( id*2+1, mid+1, e );
}
 
void upd ( int id, int b, int e, int i, int j, int val )
{
    if ( b > j || e < i ) return;
    if ( b >= i && e <= j ) {
        prop[id] += val;
        vis[id] = 1;
        return;
    }
 
    int mid = ( b + e ) >> 1;
    upd ( id*2, b, mid, i, j, val );
    upd ( id*2+1, mid+1, e, i, j, val );
}
 
ll ask ( int id, int b, int e, int i )
{
    if ( i < b || i > e ) return 0;
    if ( b == e && i == b ) return prop[id];
 
    if ( vis[id] ) shift ( id );
 
    int mid = ( b + e ) >> 1;
    ll left = ask ( id*2, b, mid, i );
    ll right = ask ( id*2+1, mid+1, e, i );
 
    return left + right;
}
 
 
int main()
{
    optimize();
 
    int n, q;
    cin >> n >> q;
    for ( int i = 1; i <= n; i++ ) cin >> a[i];
    init ( 1, 1, n );
 
    while ( q-- ) {
        int typ;
        cin >> typ;
 
        if ( typ == 1 ) {
            int a, b, u;
            cin >> a >> b >> u;
            upd ( 1, 1, n, a, b, u );
        }
        else {
            int k;
            cin >> k;
            cout << ask ( 1, 1, n, k ) << endl;
        }
    }
 
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 