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
int a[mx], t[mx*3];
 
void init ( int id, int b, int e )
{
    if ( b == e ) {
        t[id] = a[b];
        return;
    }
 
    int mid = ( b + e ) >> 1;
    init ( id*2, b, mid );
    init ( id*2+1, mid+1, e );
 
    t[id] = min ( t[id*2], t[id*2+1] );
}
 
void upd ( int id, int b, int e, int i, int val )
{
    if ( i < b || i > e ) return;
    if ( i == b && i == e ) {
        t[id] = val;
        return;
    }
 
    int mid = ( b + e ) >> 1;
    upd ( id*2, b, mid, i, val );
    upd ( id*2+1, mid+1, e, i, val );
 
    t[id] = min ( t[id*2], t[id*2+1] );
}
 
int ask ( int id, int b, int e, int l, int r )
{
    if ( b > r || e < l ) return inf;
    if ( b >= l && e <= r ) return t[id];
 
    int mid = ( b + e ) >> 1;
    int left = ask ( id*2, b, mid, l, r );
    int right = ask ( id*2+1, mid+1, e, l, r );
 
    return min ( left, right );
}
 
/// O(nlog2(n))
int main()
{
    optimize();
 
    int n, q;
    cin >> n >> q;
    for ( int i = 1; i <= n; i++ ) cin >> a[i];
 
    init ( 1, 1, n ); /// O(nlog2(n))
 
    /// O(q*log2(n))
    while ( q-- ) {
        int typ;
        cin >> typ;
        if ( typ == 1 ) {
            int k, u;
            cin >> k >> u;
            upd ( 1, 1, n, k, u ); ///O(log2(n))
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << ask ( 1, 1, n, a, b ) << endl; ///O(log2(n))
        }
    }
 
    return 0;
}
 
 
 
 
 
 
 
 