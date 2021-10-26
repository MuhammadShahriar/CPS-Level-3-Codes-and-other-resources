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

const int mx = 35;
ll dp1[mx][mx], dp2[mx][mx][65];
string s1, s2;
ll n1, n2, ans1, ans2;
int a1[mx], a2[mx];

int LCS ( int i, int j )
{
    if ( i >= n1 || j >= n2 ) return 0;
    if ( dp1[i][j] != -1 ) return dp1[i][j];

    int ret = 0;
    if ( s1[i] == s2[j] ) ret = 1 + LCS ( i+1, j+1 );
    else {
        ret = max ( LCS ( i+1, j ), LCS ( i, j+1 ) );
    }  

    return dp1[i][j] = ret;
}


ll solve ( int i, int j, int k )
{
    if ( i == n1 && j == n2 ) return ( k == ans1 );
    if ( k == ans1 ) return 0;
    if ( dp2[i][j][k] != -1 ) return dp2[i][j][k];

    ll ret = 0;

    for ( int c = 0; c < 26; c++ ) {
        ret += solve ( i + ( a1[i] == c ), j + ( a2[j] == c ), k+1 );  
    }

    return dp2[i][j][k] = ret;
}

int main()
{
	optimize();

    int T;
    cin >> T;

    for ( int tc = 1; tc <= T; tc++ ) {
        mem ( dp1, -1 );
        mem ( dp2, -1 );
        mem ( a1, -1 );
        mem ( a2, -1 );

        cin >> s1 >> s2;
        n1 = sz(s1);
        n2 = sz(s2);
        for ( int i = 0; i < n1; i++ ) a1[i] = s1[i] - 'A';
        for ( int i = 0; i < n2; i++ ) a2[i] = s2[i] - 'A';


        ans1 = n1 + n2 - LCS ( 0, 0 );
        ans2 = solve ( 0, 0, 0 );

        cout << "Case " << tc << ": " << ans1 << " " << ans2 << endl;


    }


	return 0;
}







