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


int k;
vector<int> digits;
int n;
int dp[11][100][100][3];

int solve ( int i, int m1, int m2, int flag )
{
    if ( i == n ) return ( m1 == 0 && m2 == 0 );
    if ( dp[i][m1][m2][flag] != -1 ) return dp[i][m1][m2][flag];

    int ret = 0;
    int lim = ( flag ) ? 9 : digits[i];

    for ( int j = 0; j <= lim; j++ ) {
        ret += solve ( i+1, ( ( m1 * 10 ) + j ) % k, ( m2 + j ) % k, ( flag || j < digits[i] ) );
    }

    return dp[i][m1][m2][flag] = ret;
}

int calc ( int val )
{
    digits.clear();
    while ( val > 0 ) {
        digits.PB ( val % 10 );
        val /= 10;
    }

    reverse ( all ( digits ) );
    n = digits.size();

    mem ( dp, -1 );
    return solve ( 0, 0, 0, 0 );
}


int main()
{
	optimize();

    int T;
    cin >> T;
    for ( int tc = 1; tc <= T; tc++ ) {
        int l, r;
        cin >> l >> r >> k;

        if ( k > 90 ) {
            cout << "Case " << tc << ": " << 0 << endl;
        }
        else {
            cout << "Case " << tc << ": " << calc(r) - calc(l-1) << endl;
        }
    }


	return 0;
}
















