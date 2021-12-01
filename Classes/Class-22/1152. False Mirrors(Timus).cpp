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

int n;
int a[23];
int dp[(1<<20)+123];

int solve ( int mask )
{
    if ( mask == ( 1 << n ) - 1 ) return 0;
    if ( dp[mask] != -1 ) return dp[mask];

    int dmg = 0;
    for ( int i = 0; i < n; i++ ) {
        if ( ( mask & ( 1 << i ) ) == 0 ) {
            dmg += a[i];
        }
    }

    int ret = inf;
    for ( int i = 0; i < n; i++ ) {
        if ( ( mask & ( 1 << i ) ) == 0 ) {
            int id1 = i;
            int id2 = ( i + 1 ) % n;
            int id3 = ( i + 2 ) % n;

            int tmpDmg = dmg;

            if ( ( mask & ( 1 << id1 ) ) == 0 ) tmpDmg -= a[id1];
            if ( ( mask & ( 1 << id2 ) ) == 0 ) tmpDmg -= a[id2];
            if ( ( mask & ( 1 << id3 ) ) == 0 ) tmpDmg -= a[id3];

            ret = min ( ret, tmpDmg + solve ( mask | ( 1 << id1 ) | ( 1 << id2 ) | ( 1 << id3 ) ) );
        }
    }


    return dp[mask] = ret;
}

int main()
{
	optimize();

    cin >> n;
    for ( int i = 0; i < n; i++ ) cin >> a[i];

    mem ( dp, -1 );
    cout << solve ( 0 ) << endl;


	return 0;
}















