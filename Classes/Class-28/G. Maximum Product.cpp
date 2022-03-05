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

struct info {
    int i = -1, f1 = -1, f2 = -1, f3 = -1, ans = -1;
    info(){}
    info( int i, int f1, int f2, int f3, int ans ) : i(i), f1(f1), f2(f2), f3(f3), ans(ans){}
};

vector<int> d1, d2;
int n;
ll dp[20][3][3][3];
info dir[20][3][3][3];

ll solve ( int i, int f1, int f2, int f3 )
{
    if ( i >= n ) return 1;
    if ( dp[i][f1][f2][f3] != -1 ) return  dp[i][f1][f2][f3];

    ll ret = 0;
    int b = 0, e = 9;
    if ( f1 == 0 ) b = d1[i];
    if ( f2 == 0 ) e = d2[i];

    for ( int j = b; j <= e; j++ ) {
        int k = j;
        if ( f3 == 0 ) k = max ( 1, j );
        ll res = 1LL * k * solve ( i+1, ( j > d1[i] || f1 ), ( j < d2[i] || f2 ), ( j > 0 || f3 ) );

        if ( res >= ret ) {
            ret = res;
            dir[i][f1][f2][f3] = info ( i+1, ( j > d1[i] || f1 ), ( j < d2[i] || f2 ), ( j > 0 || f3 ), j );
        }
    }

    return dp[i][f1][f2][f3] = ret;
}

void printDP ( int i, int f1, int f2, int f3 )
{
    info val = dir[i][f1][f2][f3];
    if ( val.ans == -1 ) return;
    if ( val.f3 == 1 ) cout << val.ans;
    printDP ( val.i, val.f1, val.f2, val.f3 );
}

int main()
{
	optimize();

    ll a, b;
    cin >> a >> b;

    while ( a > 0 ) {
        d1.PB ( a % 10 );
        a /= 10;
    }

    while ( b > 0 ) {
        d2.PB ( b % 10 );
        b /= 10;
    }

    n = d2.size();

    while ( n != d1.size() ) d1.PB ( 0 );

    reverse ( all ( d1 ) );
    reverse ( all ( d2 ) );

    mem ( dp, -1 );
    solve ( 0, 0, 0, 0 );
    printDP ( 0, 0, 0, 0 );

	return 0;
}















 